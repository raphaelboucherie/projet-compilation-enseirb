#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define I 0 //int
#define F 1 //float
#define S 2 //string
#define B 3 //bool
#define U -1 //indef



typedef enum { TYPE_CONTENT, TYPE_INDEX, TYPE_OP } NodeEnum;
typedef struct {
  int name; /* 操作符名称 */
  int num; /* 操作元个数 */
  int type;
  struct NodeTag * node[1]; /* 操作元地址 可扩展 */
} OpNode;

typedef struct ContentTag {
  int e;
  float f;
  char *s;
  int b; //1 -> vrai; 0 ->faux;
} Content;
 

typedef struct NodeTag {

  NodeEnum type; /* 树结点类型 */

  /* Union 必须是最后一个成员 */
  int valuetype;
  union{
    Content* content; /* 内容 */
    int index; /* 索引 */
    OpNode op; /* 操作符对象 */
  };
} Node;
 

struct VarIndex
{
  float val;
  char mark[10];
};

struct VarDefine
{

 int index;
 char * name;

};

 

#define USER_DEF_NUM 259 /* Yacc编译的保留字开始索引 */

 

#define MAX_VARS 100     /* 最多变量数 */

#define MAX_DEFS 20      /* 最多保留字数 */

 

#define MAX_BUFF_COLS 40   /* 分析语句最多行数 */

#define MAX_BUFF_ROWS 40   /* 分析语句每行最多字符数 */

 

extern struct VarIndex G_Var[MAX_VARS];  /* 存储的变量数组 */

extern struct VarDefine G_Def[MAX_DEFS]; /* 系统保留字变量 */

 

extern int G_iVarMaxIndex;   /* 变量目前总数 */

extern int G_iVarCurIndex;   /* 当前操作变量索引 */

 

extern char G_sBuff[MAX_BUFF_ROWS][MAX_BUFF_COLS];  /* 存储分析语句 */

extern int G_iBuffRowCount;  /* 当前语句行数 */

extern int G_iBuffColCount;  /* 当前语句列数 */

Content *set_content_float(float value);
Content *set_content_int(int value);
Content *set_content_string(char* value);
Content *set_content_boolean(int value);
Node *NewNodeInt(int value);
Node *NewNodeFloat(float value);
Node *NewNodeBoolean(int value);
Node *NewNodeString(char* value);
Node *set_index(int value);

Node *opr(int name, int num, ...);
void NodeFree(Node *p) ;
void init(int tab[4][4]);
void init_tab(int tab_plus[4][4],
	      int tab_mult[4][4],
	      int tab_comp[4][4]);
void NodePrint(Node *p);
// #define PARSE_DEBUG    
