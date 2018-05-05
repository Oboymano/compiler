%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  #include <stdint.h>
  extern FILE *yyin;
  
  int yylex (void);
  void yyerror (char const *);
  int check_divider (double);
  int check_mod (int);
  void init_file();
  void fprint(char*,char*);
  void fprintln();
  int addText(char *);
  void asmPrint(int,int);
  void asmLineOnly();
  void endFile();
  struct exp *createExp(double,char,int,struct exp*,struct exp*);
  struct loop *createLoop(int,int);
  void printExp(struct exp*);
  void addValue(int);
  void condition(char*);
  void loopFirst(struct loop*);
  void loopEnd(struct loop*);
  void printDec();
  void printHex();
  void println();
  void pushAll();
  void popAll();
  
  struct text {
    int id;
    char *txt;
    struct text *next;
  };

  struct exp {
    char operation;
    double value;
    int type;
    char position;
    struct exp *left,*right;
  };

  struct loop {
    int id;
    int number;
  };

  struct text *str;

  int errors = 0;
  int done = 0;
  int id=0,pow_id=0,if_id=0,loop_id=0;
  double variable[26]={0};
  char tmp[2];
  FILE *fp;

  
%}

%union {
	double f;
  char *s;
  struct exp *e;
  struct loop *l;
}

%start prog

%token<f> T_GRATHER T_LESS T_GE T_LE T_NE T_NOT T_EQUAL T_POW
%token<f> T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT  
%token<f> T_NUM T_COND T_ELSE T_LOOP T_VAL T_PRINT T_PRINTLN 
%token<f> T_HEX T_COLON T_QUOTE T_LINE T_COMMA T_ROUND
%token<s> T_STR
%token END_OF_FILE 0
%left T_PLUS T_MINUS
%left T_DIVIDE T_MULTIPLY T_MOD
%precedence NEG   
%right T_POW  

%type<f> check command
%type<e> exp
%type<l> round
%%
prog:
  input END_OF_FILE           { endFile(); }
;

input:
  %empty
| line {

  }
| input T_LINE line {
      errors=0;
  }
| input error T_LINE line {
      errors = 0;
      YYABORT;
  }
;

line:
 exp                               { printExp($1); }
| command 
| check    
; 

command: T_PRINT T_LEFT T_VAL T_RIGHT                          { 
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)$3*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                               }
| T_VAL T_EQUAL exp                                            { printExp($3); addValue((int)$1); }
| T_PRINTLN T_LEFT T_VAL T_RIGHT                               { 
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)$3*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                                  fprintf(fp,"\tCALL\tprintLineOnly\n\n");
                                                               }
| T_PRINT T_LEFT exp T_RIGHT                                   { 
                                                                  printExp($3);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                               }
| T_PRINTLN T_LEFT T_RIGHT                                     { fprintf(fp,"\tCALL\tprintLineOnly\n\n"); }
| T_PRINTLN T_LEFT exp T_RIGHT                                 { 
                                                                  printExp($3);
                                                                  pushAll(); 
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                               }
| T_PRINT T_LEFT T_VAL T_COMMA T_HEX T_RIGHT                   {  
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)$3*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll();
                                                               }
| T_PRINTLN T_LEFT T_VAL T_COMMA T_HEX T_RIGHT                 {  
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)$3*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll();
                                                                  fprintf(fp,"\tCALL\tprintLineOnly\n\n");
                                                               }
| T_PRINT T_LEFT exp T_COMMA T_HEX T_RIGHT                     { 
                                                                  printExp($3); 
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll();
                                                               }
| T_PRINTLN T_LEFT exp T_COMMA T_HEX T_RIGHT                   { 
                                                                  printExp($3); 
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll(); 
                                                                  fprintf(fp,"\tCALL\tprintLineOnly\n\n");
                                                               }
| T_PRINT T_LEFT T_QUOTE T_STR T_QUOTE T_RIGHT                 { asmPrint(addText($4),strlen($4)); }
| T_PRINTLN T_LEFT T_QUOTE T_STR T_QUOTE T_RIGHT               { asmPrint(addText($4),strlen($4)+1); }
| T_PRINT T_LEFT T_QUOTE T_VAL T_QUOTE T_RIGHT                 { sprintf(tmp,"%c",'A'+(int)$4); asmPrint(addText(tmp),1); }
| T_PRINTLN T_LEFT T_QUOTE T_VAL T_QUOTE T_RIGHT               { sprintf(tmp,"%c",'A'+(int)$4); asmPrint(addText(tmp),2); }
| T_COND T_LEFT check T_RIGHT T_COLON command                  { fprintf(fp,"if_done%d:\n",if_id++); }
| T_LOOP T_LEFT round T_RIGHT T_COLON command                  { loopEnd($3); }
;

exp: T_NUM                                  { $$ = createExp($1,' ',1,NULL,NULL); }
| T_VAL                                     { $$ = createExp($1,' ',2,NULL,NULL); }
| exp T_PLUS exp                            { 
                                              $1->position = 'l';
                                              $3->position = 'r';
                                              $$ = createExp(0,'+',0,$1,$3);
                                             }
| exp T_MINUS exp                           { 
                                              $1->position = 'l';
                                              $3->position = 'r';
                                              $$ = createExp(0,'-',0,$1,$3);
                                             }
| exp T_MULTIPLY exp                        { 
                                              $1->position = 'l';
                                              $3->position = 'r';
                                              $$ = createExp(0,'*',0,$1,$3);
                                            }
| exp T_DIVIDE exp                          { 
                                              $1->position = 'l';
                                              $3->position = 'r';
                                              $$ = createExp(0,'/',0,$1,$3);
                                            }
| exp T_MOD exp                             { 
                                              $1->position = 'l';
                                              $3->position = 'r';
                                              $$ = createExp(0,'%',0,$1,$3);
                                            }
| exp T_POW exp                             { 
                                              $1->position = 'l';
                                              $3->position = 'r';
                                              $$ = createExp(0,'^',0,$1,$3);
                                            }
| T_MINUS exp %prec NEG                     { 
                                              $2->position = 'r';
                                              $$ = createExp(0,'_',0,NULL,$2); 
                                            }
| T_LEFT exp T_RIGHT                        { $$ = createExp(0,$2,1,NULL,NULL); }
;

check: exp T_GRATHER exp                    { 
                                              printExp($1);
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp($3);
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition(">");
                                            }
| exp T_LESS exp                            { 
                                              printExp($1);
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp($3);
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("<");
                                            }
| exp T_GE exp                              { 
                                              printExp($1);
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp($3);
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition(">=");
                                            }
| exp T_LE exp                              { 
                                              printExp($1);
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp($3);
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("<=");
                                            }
| exp T_NE exp                              { 
                                              printExp($1);
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp($3);
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("!=");
                                            }
| exp T_EQUAL exp                           { 
                                              printExp($1);
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp($3);
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("=");
                                            }                                       
;

round:T_ROUND                               {
                                              $$=createLoop(loop_id++,(int)$1);
                                              loopFirst($$);
                                            }
%%

int main(){
  
    init_file();
    
    yyin = fopen("com.txt","r");
    
    yyparse();

    fclose(yyin);
    
}

void yyerror(const char *s)
{
  errors++;
  printf("%s\n",s);
}

int check_divider(double div)
{
  if(div == 0)
  {
    printf("can't divider by zero\n");
    errors = 1;
    return 0;
  }
  return 1;
}

int check_mod(int mod)
{
  if(mod == 0)
  {
    printf("can't mod\n");
    return 0;
  }
  return 1;
}

struct exp * createExp(double value,char operation,int type,struct exp *left,struct exp *right){
  struct exp *exps = malloc(sizeof(struct exp));
  exps->value = value;
  exps->operation = operation;
  exps->type = type;
  exps->position = ' ';
  exps->left = left;
  exps->right = right;
  return exps;
}

void init_file(){
  fp = fopen("file.asm","w");
  fprint("section",".text");
  fprintln("");
  fprint("\tglobal","_start");
  fprintln("");
  fprintln("_start:");
}
void fprint(char *first,char *second){
  fprintf(fp,"%s\t%s",first,second);
}
void fprintln(char *label){
  fprintf(fp,"%s\n",label);
}
void asmPrint(int id,int length){
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,text%d\n",id);
  fprintf(fp,"\tMOV\trdx,%d\n",length);
  fprintf(fp,"\tsyscall\n\n");
}
void asmLineOnly(){
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,line\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n\n");
}
int addText(char *txt){
  struct text *tmp_str = str;
  int id_return=0;
  if(tmp_str==NULL){
    tmp_str = malloc(sizeof(struct text));
    tmp_str->txt = txt;
    tmp_str->id=id++;
    tmp_str->next=NULL;
    str = tmp_str;
    id_return=tmp_str->id;
  }else {
    while(tmp_str->next!=NULL){
      tmp_str=tmp_str->next;
    }
    tmp_str->next = malloc(sizeof(struct text));
    tmp_str->next->txt = txt;
    tmp_str->next->id=id++;
    id_return=tmp_str->next->id;
  }
  return id_return;
}
void endFile(){
  fprintf(fp,"\tMOV\trax,60\n");
  fprintf(fp,"\tMOV\trdi,0\n");
  fprintf(fp,"\tsyscall\n\n");
  printDec();
  printHex();
  println();
  fprint("section",".data");
  fprintln("");
  fprintf(fp,"\tline\tdb 0x0A\n");
  fprintf(fp,"\tvalue\tTIMES 26 DQ 0\n");
  fprintf(fp,"\tbuffer\tresb\t20\n");
  fprintf(fp,"\tminus\tdb\t\'-\'\n");
  if(str!=NULL){
    while(str->next!=NULL){
      fprintf(fp,"\ttext%d\tdb\t\'%s\',10",str->id,str->txt);
      fprintln("");
      str=str->next;
    }
    fprintf(fp,"\ttext%d\tdb\t\'%s\',10",str->id,str->txt);
    fprintln("");
  }
  fclose(fp);
}
void printExp(struct exp *exps){

  if(exps->left!=NULL)
    printExp(exps->left);
  if(exps->right!=NULL){
    fprintf(fp,"\tPUSH\tr8\n");
    printExp(exps->right);
    fprintf(fp,"\tPOP\tr8\n");
  }

  if(exps->type==0){
    if(exps->operation=='+'){
        if(exps->position=='l'){
          fprintf(fp,"\tADD\tr8,r9\n");
        }else if(exps->position=='r') {
          fprintf(fp,"\tADD\tr9,r8\n");
        }else if(exps->position==' ') {
          fprintf(fp,"\tADD\tr8,r9\n");
          fprintf(fp,"\tMOV\trax,r8\n\n");
        }
    } else if(exps->operation=='-'){ 
        if(exps->position=='l'){
          fprintf(fp,"\tSUB\tr8,r9\n");
        }else if(exps->position=='r'){
          fprintf(fp,"\tSUB\tr9,r8\n");
        }else {
          fprintf(fp,"\tSUB\tr8,r9\n");
          fprintf(fp,"\tMOV\trax,r8\n\n");
        }
    } else if(exps->operation=='*'){ 
        fprintf(fp,"\tMOV\trax,r8\n");
        fprintf(fp,"\tIMUL\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,rax\n");
        }else if(exps->position=='r'){
          fprintf(fp,"\tMOV\tr9,rax\n");
        }else {
          fprintf(fp,"\n");
        }
    } else if(exps->operation=='/'){ 
        fprintf(fp,"\tMOV\trax,r8\n");
        fprintf(fp,"\tIDIV\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,rax");
        }else if(exps->position=='r'){
          fprintf(fp,"\tMOV\tr9,rax\n");
        }else {
          fprintf(fp,"\n");
        }
    } else if(exps->operation=='%'){
        fprintf(fp,"\tMOV\trax,r8\n");
        fprintf(fp,"\tIDIV\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,rdx");
        }else if(exps->position=='r'){
          fprintf(fp,"\tMOV\tr9,rdx\n");
        }else {
          fprintf(fp,"\n");
        }
    } else if(exps->operation=='_'){
        fprintf(fp,"\tNEG\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,r9\n");
        }else if(exps->position=='r'){
          //fprintf(fp,"\tMOV\tr9,rdx\n");
        }else {
          fprintf(fp,"\tMOV\trax,r9\n\n");
        }
    }
  } else if(exps->type==1){
    if(exps->position=='l'){
      fprintf(fp,"\tMOV\tr8,%d\n",(int)exps->value);
    }else if(exps->position=='r'){
      fprintf(fp,"\tMOV\tr9,%d\n",(int)exps->value);
    }else if(exps->position==' '){
      fprintf(fp,"\tMOV\trax,%d\n\n",(int)exps->value);
    }
    
  } else if(exps->type==2){
    if(exps->position=='l'){
      fprintf(fp,"\tMOV\tr8,[value+%d]\n",(int)exps->value*8);
    }else if(exps->position=='r'){
      fprintf(fp,"\tMOV\tr9,[value+%d]\n",(int)exps->value*8);
    }else if(exps->position==' '){
      fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)exps->value*8);
    }
  }
}
void addValue(int id){
  fprintf(fp,"\tMOV\t[value+%d],rax\n",id*8);
}
void condition(char *operation){
  fprintf(fp,"\tCMP\trbx,rax\n");
  if(!strcmp(operation,">")){
    fprintf(fp,"\tJLE\tif_done%d\n",if_id);
  }else if(!strcmp(operation,"<")){
    fprintf(fp,"\tJGE\tif_done%d\n",if_id);
  }else if(!strcmp(operation,">=")){
    fprintf(fp,"\tJL\tif_done%d\n",if_id);
  }else if(!strcmp(operation,"!=")){
    fprintf(fp,"\tJE\tif_done%d\n",if_id);
  }else if(!strcmp(operation,"=")){
    fprintf(fp,"\tJNE\tif_done%d\n",if_id);
  }
  //fprintf();
}
struct loop *createLoop(int id,int number){
  struct loop *loops = malloc(sizeof(struct loop));
  loops->id = id;
  loops->number = number;
  return loops;
}
void loopFirst(struct loop* loops){
  fprintf(fp,"\tPUSH\tr10\n");
  fprintf(fp,"\tMOV\tr10,%d\n",loops->number);
  fprintf(fp,"loop%d:\n",loops->id);
}
void loopEnd(struct loop* loops){
  fprintf(fp,"\tDEC\tr10\n");
  fprintf(fp,"\tCMP\tr10,1\n");
  fprintf(fp,"\tJGE\tloop%d\n",loops->id);
  fprintf(fp,"\tPOP\tr10\n");
}
void printDec(){
  fprintf(fp,"printDec:\n");
  fprintf(fp,"\tMOV\tr10,0\n");
  fprintf(fp,"\tMOV\tr11,0\n");
  fprintf(fp,"\tLEA\trdi,[buffer+19]\n");
  fprintf(fp,"\tXOR\trdx,rdx\n");
  fprintf(fp,"\tCMP\trax,0\n");
  fprintf(fp,"\tJGE\tnot_zero\n");
  fprintf(fp,"\tNEG\trax\n");
  fprintf(fp,"\tMOV\tr11,1\n");
  fprintf(fp,"not_zero:\n");
  fprintf(fp,"\tMOV\trbx,10\n");
  fprintf(fp,"\tdiv\trbx\n");
  fprintf(fp,"\tadd\trdx,'0'\n");
  fprintf(fp,"\tmov\tbyte[rdi],dl\n");
  fprintf(fp,"\tdec\trdi\n");
  fprintf(fp,"\tinc\tr10\n");
  fprintf(fp,"\txor\trdx,rdx\n");
  fprintf(fp,"\tcmp\trax,0\n");
  fprintf(fp,"\tjne\tnot_zero\n");
  fprintf(fp,"\tcmp\tr11,1\n");
  fprintf(fp,"\tJNE\tplus\n");
  fprintf(fp,"\tPUSH\trax\n");
  fprintf(fp,"\tPUSH\trdi\n");
  fprintf(fp,"\tPUSH\trdx\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,minus\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tPOP\trax\n");
  fprintf(fp,"\tPOP\trdi\n");
  fprintf(fp,"\tPOP\trdx\n");
  fprintf(fp,"plus:\n");
  fprintf(fp,"\tINC\trdi\n");
  fprintf(fp,"\tMOV\trbx,rdi\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,rbx\n");
  fprintf(fp,"\tMOV\trdx,r10\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tret\n\n");
}
void printHex(){
  fprintf(fp,"printHex:\n");
  fprintf(fp,"\tMOV\tr10,0\n");
  fprintf(fp,"\tMOV\tr11,0\n");
  fprintf(fp,"\tLEA\trdi,[buffer+19]\n");
  fprintf(fp,"\tXOR\trdx,rdx\n");
  fprintf(fp,"\tCMP\trax,0\n");
  fprintf(fp,"\tJGE\tnot_zeroHex\n");
  fprintf(fp,"\tNEG\trax\n");
  fprintf(fp,"\tMOV\tr11,1\n");
  fprintf(fp,"not_zeroHex:\n");
  fprintf(fp,"\tMOV\trbx,16\n");
  fprintf(fp,"\tdiv\trbx\n");
  fprintf(fp,"\tCALL\tconvert\n");
  fprintf(fp,"\tmov\tbyte[rdi],dl\n");
  fprintf(fp,"\tdec\trdi\n");
  fprintf(fp,"\tinc\tr10\n");
  fprintf(fp,"\txor\trdx,rdx\n");
  fprintf(fp,"\tcmp\trax,0\n");
  fprintf(fp,"\tjne\tnot_zeroHex\n");
  fprintf(fp,"\tcmp\tr11,1\n");
  fprintf(fp,"\tJNE\tplusHex\n");
  fprintf(fp,"\tPUSH\trax\n");
  fprintf(fp,"\tPUSH\trdi\n");
  fprintf(fp,"\tPUSH\trdx\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,minus\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tPOP\trax\n");
  fprintf(fp,"\tPOP\trdi\n");
  fprintf(fp,"\tPOP\trdx\n");
  fprintf(fp,"plusHex:\n");
  fprintf(fp,"\tINC\trdi\n");
  fprintf(fp,"\tMOV\trbx,rdi\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,rbx\n");
  fprintf(fp,"\tMOV\trdx,r10\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tret\n\n");
  fprintf(fp,"convert:\n");
  fprintf(fp,"\tCMP\trdx,10\n");
  fprintf(fp,"\tJL\tconvert_done\n");
  fprintf(fp,"\tADD\trdx,0x7\n");
  fprintf(fp,"convert_done:\n");
  fprintf(fp,"\tADD\trdx,0x30\n");
  fprintf(fp,"\tret\n\n");
}
void pushAll(){
  fprintf(fp,"\tPUSH\tr10\n");
  fprintf(fp,"\tPUSH\tr11\n");
  fprintf(fp,"\tPUSH\trdi\n");
  fprintf(fp,"\tPUSH\trdx\n");
  fprintf(fp,"\tPUSH\trax\n");
  fprintf(fp,"\tPUSH\trbx\n\n");
}
void popAll(){
  fprintf(fp,"\tPOP\trbx\n");
  fprintf(fp,"\tPOP\trax\n");
  fprintf(fp,"\tPOP\trdx\n");
  fprintf(fp,"\tPOP\trdi\n");
  fprintf(fp,"\tPOP\tr11\n");
  fprintf(fp,"\tPOP\tr10\n\n");
}
void println(){
  fprintf(fp,"printLineOnly:\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,line\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tret\n\n");
}
