//+doc several dummy definitions,
// mostly locale related.
// (locales are not the target of minilib,
// so define mini_dummies to have code relying on locales 
// running)
// Quite often some code does only checking for locales,
// but doesn't rely on them.
//+include
//+def locale_dummies


#define wctype(x) (0)

#define iswctype(x,y) (0)

#define wcscoll(s1,s2) strcmp(s1,s2)

#define strcoll(s1,s2) strcmp(s1,s2)


