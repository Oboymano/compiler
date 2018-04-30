%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include <stdint.h>
  
  int yylex (void);
  void yyerror (char const *);
  int check_divider (double);
  int check_mod (int);
  void init_file();
  void fprint(char*,char*);
  void fprintln();
  

  int errors = 0;
  int done = 0;
  double variable[26]={0};
  FILE *fp;
%}

%define api.value.type {double}
%token T_GRATHER T_LESS T_GE T_LE T_NE T_NOT T_EQUAL T_POW
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT  
%token T_NUM T_COND T_ELSE T_LOOP T_VAL T_PRINT T_PRINTLN 
%token T_HEX T_STR T_COLON T_QUOTE T_LINE T_COMMA T_EXIT
%left T_PLUS T_MINUS
%left T_DIVIDE T_MULTIPLY T_MOD
%precedence NEG   
%right T_POW  

%%
input:
  %empty
| input line  {
      printf("> ");
      errors=0;
  }
| input error line {
      errors = 0;
      YYABORT;
  }
;

line: T_LINE
| exp T_LINE                             { printf("%g\n",$1); }
| T_VAL T_EQUAL exp T_LINE               { variable[(int)$1]=$3; }
| command T_LINE  
| check T_LINE   
| T_EXIT T_LINE                          { fclose(fp); }                      
;

command: T_PRINT T_LEFT T_VAL T_RIGHT T_LINE                         { printf("%.2f",variable[(int)$3]); }
| T_PRINTLN T_LEFT T_VAL T_RIGHT T_LINE                              { printf("%.2f\n",variable[(int)$3]); }
| T_PRINT T_LEFT exp T_RIGHT T_LINE                                  { printf("%.2f",$3); }
| T_PRINTLN T_LEFT T_RIGHT T_LINE                                    { printf("\n"); }
| T_PRINTLN T_LEFT exp T_RIGHT T_LINE                                { printf("%.2f\n",$3); }
| T_PRINT T_LEFT T_VAL T_COMMA T_HEX T_RIGHT T_LINE                  { printf("0x%X",(int)variable[(int)$3]); }
| T_PRINTLN T_LEFT T_VAL T_COMMA T_HEX T_RIGHT T_LINE                { printf("0x%x\n",(int)variable[(int)$3]); }
| T_PRINT T_LEFT exp T_COMMA T_HEX T_RIGHT T_LINE                    { printf("0x%X",(int)$3); }
| T_PRINTLN T_LEFT exp T_COMMA T_HEX T_RIGHT T_LINE                  { printf("0x%X\n",(int)$3); }
| T_PRINT T_LEFT T_QUOTE T_STR T_QUOTE T_RIGHT T_LINE                { printf("%s",$4); }
| T_COND T_LEFT check T_RIGHT T_COLON command                        { if($3) $6 ; }
;

exp: T_NUM                                  { $$ = $1; }
| exp T_PLUS exp                            { $$ = $1 + $3; }
| exp T_MINUS exp                           { $$ = $1 - $3; }
| exp T_MULTIPLY exp                        { $$ = $1 * $3; }
| exp T_DIVIDE exp                          { if(check_divider($3)) {$$ = $1 / $3;}else YYABORT; }
| exp T_MOD exp                             { if(check_mod($3)) {$$ = (int)$1 % (int)$3;} else YYABORT; }
| exp T_POW exp                             { $$ = pow($1,$3); }
| T_MINUS exp %prec NEG                     { $$ = -$2; }
| T_LEFT exp T_RIGHT                        { $$ = $2; }
;

check: exp T_GRATHER exp                    { 
                                              if($1 > $3){
                                                 $$ = 1;
                                              } else {$$ = 0;} 
                                            }
| exp T_LESS exp                            { 
                                              if($1 < $3){
                                                $$ = 1;
                                              }else {$$ = 0;} 
                                            }
| exp T_GE exp                              { 
                                              if($1 >= $3){
                                              $$ = 1;
                                              }else {$$ = 0;} 
                                            }
| exp T_LE exp                              { 
                                              if($1 <= $3){
                                              $$ = 1;
                                              }else {$$ = 0;} 
                                            }
| exp T_NE exp                              { 
                                              if($1 != $3){
                                              $$ = 1;
                                              }else {$$ = 0;} 
                                            }
| exp T_EQUAL exp                           { 
                                              if($1 == $3){
                                              $$ = 1;
                                              }else {$$ = 0;} 
                                            }                                       
;
%%

int main(){
    init_file();
    while(1){
        printf("> ");
        yyparse();
    }
    
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

