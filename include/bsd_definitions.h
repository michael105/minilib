//+doc definitions, found at BSD
// enable with mini_bsd_definitions
//+include
//+def bsd_definitions






#define __predict_true(x) __builtin_expect(x,1)  
#define __predict_false(x) __builtin_expect(x,0)  




