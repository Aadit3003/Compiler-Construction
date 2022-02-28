#define NON_TERMINALS 49
#define TERMINALS 52
#define NUM_RULES 100
#include "gterm.h"


// GRAMMAR DATA STRUCTURES
typedef struct rhs{ 
	g_Term symbol;
	bool isTerminal;
	struct RHS* next;
} g_RHS;

typedef struct ruleHead{
	
	g_RHS* listHead; 	//pointer to the linked list
	struct ruleHead* next; 	//pointer to next rule

}ruleHead;

typedef ruleHead* Grammar[NON_TERMINALS];
//

// PARSE TABLE DATA STRUCTURES
typedef struct firstAndFollowSet{
	int** first; 
	int** follow;
} FirstAndFollow;

g_RHS* parseTable[NON_TERMINALS][TERMINALS];

bool First[NON_TERMINALS + TERMINALS + 1][TERMINALS + 1];
bool Follow[NON_TERMINALS][TERMINALS+2];

//


// GRAMMAR Functions
g_RHS* insertIntoRule(g_RHS* head, g_Term s, bool isTerm);
ruleHead* insertRuleList(ruleHead* head, g_RHS* rule);
void printGrammar(Grammar G, int len);
void printRules(ruleHead* head);
void printRule(g_RHS* head);
void printToken(int token);
void printNonTerminal(int token);

// PARSE TABLE Functions

bool* set_union(bool* A, bool*B, int len);

bool* computeFirst(g_RHS* head, g_Term lhs);