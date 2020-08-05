

==========
declarations.h
==========



==========
dirent.h
==========

closedir       int closedir(DIR *dir);

               (src/dirent/closedir.c: 6)

opendir        static DIR *opendir(const char *name );

               (src/dirent/opendir.c: 24)

readdir        struct dirent *readdir(DIR *dir);

               read a directory.
              return the next dirent, or 0, if the end is reached.
              return 0 on error and set errno,
              if mini_errno is not defined, return -errno on error
               (src/dirent/readdir.c: 10)

rewinddir      void rewinddir(DIR *dir);

               (src/dirent/rewinddir.c: 2)

scandir        int scandir(const char *path, struct dirent **listing[], int (*fp_select)(const struct dirent *),	int (*cmp)(const struct dirent **, const struct dirent **));

               list files and dirs in a directory
             
              This implementation uses malloc_brk() for the dynamic allocation
              of the listing, and tries to do as less copies as possible.
              The dynamically allocated space for the result list (**listing[])
              is guaranteed to be at one continuous memory location.
             
              if the select callback is 0, meaning all entries should be returned,
              There are no copies done at all, 
              besides the copying from kernelspace to userspace.
             
              To free the space, allocated for the listing,
              either call free_brk(),
              when no other allocations via malloc_brk took place.
             
              Or save the brk before you call scandir,
              and restore it after the call.
              (e.g.)
              long savebrk=getbrk();
              int ret=scandir(...);
              brk(savebrk);
              Freeing single list entries might give unexpected results.
             
              returns the number of the read entries,
              or the negative errno on error.
               (src/dirent/scandir.c: 35)

seekdir        void seekdir(DIR *dir, long off);

               (src/dirent/seekdir.c: 2)

telldir        long telldir(DIR *dir);

               (src/dirent/telldir.c: 2)



==========
fcntl.h
==========

creat          int volatile creat( const char *s, int mode );

               (src/open.c: 36)

mkfifo         static int mkfifo( const char* path, mode_t mode );

               (include/mkfifo.h: 4)



==========
ioctl.h
==========

ioctl          int volatile  __attribute__((optimize("O0"))) ioctl( int fd, unsigned long int request, ... );

               (src/ioctl.c: 11)



==========
mini_addons.h
==========

OPTFENCE       static void __attribute__((noipa,cold,naked)) opt_fence(void*p,...);

               prevent gcc to optimize away registers and variables
              the macro OPTFENCE(...) can be invoked with any parameter.
              The parameters will get calculated, even if gcc doesn't recognize
              the use of the parameters, e.g. cause they are needed for an inlined asm syscall.
             
              The macro translates to an asm jmp and a function call to the function 
              opt_fence, which is defined with the attribute "noipa" -
              (the compiler "forgets" the function body, so gcc is forced
              to generate all arguments for the function)
              The generated asm jump hops over the call to the function,
              but this gcc doesn't recognize.
             
              This generates some overhead, 
              (a few (never reached) bytes for setting up the function call, and the jmp)
              but I didn't find any other solution,
              which gcc wouldn't cut for optimizations from time to time.
              (volatile, volatile asm, optimize attributes, 
              andsoon have all shown up to be unreliable - sometimes(!)).
             
              Had some fun debugging these bugs, which naturally showed up only sometimes.
              (Many syscalls also work with scrambled arguments..)
              And, I believe it IS a compiler bug. 
              Volatile should be volatile for sure, not only sometimes.
              I mean, why the heck do I write volatile?? 
               (include/syscall.h: 65)

_itobin        int _itobin(int i, char*buf, int prec, int groups );

               (src/itobin.c: 8)

_mprints       #define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

               (include/prints.h: 10)

alphasort      int alphasort( const struct dirent** de1, const struct dirent** de2 );

               Sort dirents by name.
              Deviating of the standard, 
              the asciitables is used for the comparison
              (using strcmp)
               (src/dirent/alphasort.c: 7)

ansicolors     

               defines for ansicolors at the console, 16 color mode
             the names are:
              AC_NORM ( white text on black background)
              AC_BLACK 
              AC_RED 
              AC_GREEN 
              AC_BROWN 
              AC_BLUE 
              AC_MAGENTA 
              AC_MARINE (= AC_CYAN)
              AC_LGREY 
              AC_WHITE 
              AC_GREY 
              AC_LRED 
              AC_LGREEN 
              AC_YELLOW 
              AC_LBLUE 
              AC_LMAGENTA 
              AC_LMARINE (= AC_LCYAN)
              AC_LWHITE 
              AC_BGBLACK 
              AC_BGRED 
              AC_BGGREEN 
              AC_BGBROWN 
              AC_BGBLUE 
              AC_BGMAGENTA 
              AC_BGMARINE 
              AC_BGLGREY 
              AC_BGWHITE 
             
              AC_BOLD
              AC_FAINT
              AC_CURSIVE
              AC_UNDERLINE
              AC_LIGHTBG
              AC_BLINK
              AC_INVERTED
              AC_INVERSE
             
              ( Faint to inverse are not available at every terminal )
               (include/ansicolors.h: 45)

basename       char *basename(char *path);

               (src/basename.c: 2)

brk            static int brk( const void* addr );

               set the brk to addr
              return 0 on success.
              conformant brk, when mini_errno is defined return -1 and set errno.
              if errno isn't available,
              returns the negative errno value on error
               (src/brk.c: 19)

clone_t        int clone_t(int flags);

               (src/clone.c: 7)

def            #define SETOPT_short( opts, option ) (;

               Set a option flag(s) (bit(s))  manually.
             		param options: e.g. just a, or ( a+h+l) to check for several flags at once
               (macros/getoptm.h: 52)

dirbuf         

               the switch for defining the dirbuf.
              used internally
               (include/dirent.h: 7)

dirbufsize     #ifndef mini_dirbufsize

               the dir stream bufsize
              The size of the buffer can be changed by setting mini_dirbufsize
              to it's size in Bytes. (default 2048)
              The buffer is allocated via malloc,
              therefore mini_buf must be set to a value greater than dirbufsize
               (include/dirent.h: 22)

dirfd          int dirfd(DIR *d);

               (src/dirent/dirfd.c: 2)

dirname        char *dirname(char *s);

               (src/dirname.c: 8)

djb2_hash      unsigned long djb2_hash(const unsigned char *str);

               hashes, from d.j.Bernstein
              (http://www.cse.yorku.ca/~oz/hash.html)
              I've tested djb2_hash, and it gives quite good results.
              But I'm sure, Bernstein did think and test his algorithm sincerely.
              When combining djb2_hash and sdbm_hash, the probability of collisions
              might tend to zero.
              Me I'm going this way. I guess. I might check djb2_hash for collisions within a space of around 8 digits.
               (src/hashes.c: 10)

dprintf        int dprintf( int fd, const char *fmt, ... );

               (src/dprintf.c: 5)

dprints        int dprints(int fd, const char *msg,...);

               (src/prints.c: 17)

dtodec         int dtodec(double d, char* buf, int precision);

               (src/dtodec.c: 10)

eprint         #define eprint(str) write(STDERR_FILENO,str,strlen(str))

               write str to stderr. Needs strlen
               (include/prints.h: 58)

eprintfs       #define eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)

               write fmt and arguments to stderr. 
              only format %s and %c are recognized
               (include/prints.h: 106)

eprintl        #define eprintl() write(STDERR_FILENO,"\n",1)

               write a newline to stderr
               (include/prints.h: 67)

eprints        #define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stdout
              this macro has an variable argument count.
               (include/prints.h: 25)

eprintsl       #define eprintsl(...) dprints(STDERR_FILENO,__VA_ARGS__,"\n",0)

               print the string(s) supplied as arg(s) and newline to stderr
               (include/prints.h: 47)

eputs          #define eputs(msg) ( eprint(msg) + eprintl() )

               write msg to stderr, append a newline. Needs strlen.
               (include/prints.h: 77)

errno_str      static char *errno_str(int err);

               convert errno to str, with 3 chars length
              ending the string (global) 
              with two \0\0, when errno<100
              errnum must be <200.
               (src/errno_str.c: 7)

ewrites        #define ewrites(str) write(STDERR_FILENO,str,sizeof(str))

               write the constant str to stderr. Computes length with sizeof(str) at compile time.
               (include/prints.h: 88)

exit_errno     void exit_errno( int errnum );

               exit, and execute /bin/errno
              this is intended to give a error message for the 
              given errno num.
              Instead of having the error messages compiled 
              into each binary, they can stay within one executable, "errno"
              This spares about 4kB, but needs errno installed to /bin/errno
              It's the drawback of not having a shared library,
              where all executables would share the same errno messages
              in memory.
              On the other hand, a shared library would need to be installed
              as well.
              The supplied errno can be negative,
              the absolute value is supplied to errno.
               (src/exit_errno.c: 17)

ext_match      int ext_match(char *text, const char *re, void(*p_match)(int number, char *pos,int len), int(*p_match_char)(int number, char *match_char), regex_match *st_match);

               regex engine
              This is somewhere between a fully fledged expression machine,
              and a simplicistic solution.
              The engine matches from left to right,
              backtracking is done as less as possible.
              Since the matching is nongreedy in general,
              many tries can be spared. Opposed to another route,
              where most patterns are per default greedy, and therfore
              not the first matching next char is seeked for, but the first
              solution while matching the most chars.
              (I do not want to make this a hard statement, and it 
              depends onto each pattern. But it is the way, the solution
              of the pattern is searched for, in most patterns.)
              This shows up in the logic of the patterns, which is more natural to me.
             
              It is a compromise between performance, size
              and capabilities.
              The logic is different of a "regular" regular expression
              machine, but has advantages (and disadvantages).
              I'd say, the main advantage is the easiness of adding callbacks,
              and defining your own matching/logic within these. 
              Performance might be better as well overall,
              but this depends also on the expressions.
             
              A few nonextensive benchmarks show,
              this engine is a bit faster than perl's regular expression machine,
              slower than gnu grep (around factor2), and has the same speed as sed.
              This might however vary with each usecase.
              In favor of codesize I'm not going to optimize ext_match,
              but there would be several possibilities, if you'd need a faster engine.
              (Albite I'd like to emphasise, sed (and ext_match), also perl, are quite fast.
              About 10 times faster than most expression engines.)
             
              matches: 
              
              * for every count of any char
              + for 1 or more chars
              ? for 1 char
              # for space or end of text (0)
              $ match end of text
             
              backslash: escape *,?,%,$,!,+,#,& and backslash itself.
              !: invert the matching of the next character or character class
              ,: separator. e.g. %,1 matches like ?*1. 
                ( without the commata, the '1' would be part of the % match)
               
             
              predefined character classes:
              \d - digit
              \D - nondigit
              \s - space
              \S - nonspace
              \w - word character ( defined as ascii 32-126,160-255 )
              \W - nonword character ( defined as ascii 0-31,127-159 )
             
             
              [xyz]: character classes, here x,y or z 
                the characters are matched literally, also \,*,?,+,..
                it is not possible to match the closing bracket (])
                within a character class
             
              {nX}: counted match
               Match n times X.
               For X, all expressions are allowed.
               If you need to match a number at the first char of 'X',
               separate X by a commata. E.g. {5,0} matches 5 times '0'.
             
              %[1]..%[9]: matches like a '+',
               and calls the callback supplied as 3rd argument (when not null).
               the number past the %, e.g. %1, is optional,
               p_match will be callen with this number
               as first parameter.
               When not supplied, p_matched will be callen with 
               the parameter 'number' set to 0.
             
               The matching is 'nongreedy'.
               It is possible to rewrite the string to match
               from within the p_matched callback.
               This will not have an effect onto the current matching,
               even if text is e.g. deleted by writing 0's.
               The matched positions are called in reverse order.
               (The last matched % in the regex calls p_match first, 
               the first % in the regex from the left will be callen last)
             
              supply 0 for p_matched, when you do not need to extract matches.
              This will treat % in the regex like a *, 
              a following digit (0..9) in the regex is ignored.
              if the 5th argument, a pointer to a regex_match struct, 
              is supplied, it will be filled with the first match.
              (counting from left)
             
             
              &[1] .. &[9]
               "match" like a '?' and call p_match_char
               p_match_char has to return either RE_MATCH, RE_NOMATCH, RE_MATCHEND
               or a number of the count of chars, which have been matched.
             
               Therefore it is possible to e.g. rule your own
               character classes, defined at runtime, 
               or do further tricks like changing the matched chars,
               match several chars, andsoon.
               When returning RE_NOMATCH,
               it is possible, the p_match and p_match_char callbacks are callen several times,
               but with different pos or len parameters.
             
               The matching works straight from left to right.
               So, a "*&*" will call the callback & for the first char.
               When returning RE_NOMATCH, the second char will be matched.
               Until either RE_MATCH is returned from the callback,
               or the last char has been matched.
             
               Matching several characters is also posssible from within the callback,
               the position within the text will be incremented by that number,
               you return from the callback.
             
               When returning RE_MATCHEND from the callback, 
               the whole regular expression is aborted, and returns with matched;
               no matter, if there are chars left in the expression.
             
             
               The difference between % and & is the logic.
               % matches nongreedy, and has to check therefore the right side of the star
               for its matching.
               Possibly this has to be repeated, when following chars do not match.
             
               & is matched straight from left to right.
               Whatever number you return, the textpointer will be incremented by that value.
               However, a & isn't expanded on it's own. ( what a % is ).
               e.g. "x%x" will match 'aa' in xaax, x&x will match the whole expression
               only, when you return '2' from the callback.
             
               Performancewise, matching with & is faster,
               since the % has on its right side to be matched
               with recursing calls of ext_match.
             
              When using closures for the callbacks, you will possibly have to
              enable an executable stack for the trampoline code
              of gcc. Here, gcc complains about that. 
              For setting this bit, have a look into the ldscripts in the folder
              with the same name.
             
              supply 0 for p_match_char, when you don't need it.
              This will treat & in the regex like ?, 
              and match a following digit (0..9) in the text,
              a following digit (0..9) in the regex is ignored.
              
              -----
              In general, you have to somehow invert the logic of regular expressions
              when using ext_match.
              e.g. when matching the parameter 'runlevel=default' at the kernel's
              commandline, a working regular expression would be
              "runlevel=(\S*)". This could be written here as "*runlevel=%#".
              For matching e.g. numbers, you'd most possibly best of
              with writing your own & callback.
             
              returns: 1 on match, 0 on no match
              ( RE_MATCH / RE_NOMATCH )
             
              if the pointer (argument 5) st_match is nonnull,
              the supplied struct regex_match will be set to the first matching '%' location;
              if there is no match, regex_match.len will be set to 0.
              The struct is defined as: 
              typedef struct _regex_match { char* pos; int len; } regex_match;
             
             
              (memo) When the regex ist defined within C/cpp source code,
              a backslash has to be defined as double backslash.
             
              (note) - be careful when negating a following *, or ?.
               somehow - it is logical, but seems to me I overshoot a bit,
               tragically hit my own foot, and stumbled into a logical paradox.
             
               Negating EVERYTHING translates to true.
               However, since truth is negated as well, there's a problem,
               cause it's now 'false', but 'false' is true. This is very close
               to proving 42 is the answer. What is the escape velocity
               in km/s out of the solar system, btw.
             
               (I'm not kidding here. Just don't do a regex with !* or !?..
               And, please, do not ask me what is going to happen when the impossible
               gets possibilized. I have to point at the according sentences of the BSD license;//  there is NO WARRANTY for CONSEQUENTIAL DAMAGE, LOSS OF PROFIT, etc pp.)
             
               A "!+" will translate into nongreedy matching of any char, however;
               "%!+" will match with % everything but the last char;
               while "%+" matches with % only the first char.
               !+ basically sets the greedyness of the left * or % higher.
               (src/ext_match.c: 189)

ext_match2     char* ext_match2(char *text, char *re, void(*p_match)(int number, char *pos,int len), int(*p_match_char)(int number, char *match_char), regex_match *st_match);

               regex engine
              WORK IN PROGRESS, please use ext_match
             
              This is somewhere between a fully fledged expression machine,
              and a simplicistic solution.
              The engine matches from left to right,
              backtracking is done as less as possible.
              Since the matching is nongreedy in general,
              many tries can be spared. Opposed to another route,
              where most patterns are per default greedy, and therfore
              not the first matching next char is seeked for, but the first
              solution while matching the most chars.
              (I do not want to make this a hard statement, and it 
              depends onto each pattern. But it is the way, the solution
              of the pattern is searched for, in most patterns.)
              This shows up in the logic of the patterns, which is more natural to me.
              Your mileage might vary.
             
             
              It is a compromise between performance, size
              and capabilities.
              The logic is different of a "regular" regular expression
              machine, but has advantages (and disadvantages).
              I'd say, the main advantage is the easiness of adding callbacks,
              and defining your own matching/logic within these. 
              Performance might be better as well overall,
              but this depends on the expressions and usecases as well.
             
              Yet I for myself have to get a grip of the possibilities of this engine.
              However, I have the feeling, the logic is much more natural.
              With regular regexes you always have to think kind of 'backwards',
              e.g., match ".*" -> match "." (any char) x times. 
              gets to a simple "*"
              or, to match all group and user id's of /etc/passwd,
              a regular expression would be: "(\d*):(\d*)"
              This is here: "*(\d*):(\d*)*"
              The content in the brackets looks the same,
              but it's matched quite different.
              The regular expression (the first) matches x times \d, for x>=0.
              In the second expressin, the ext_match expression,
              the first digit is matched, and then nongreedy any chars, until
              the first occurence of ':'. 
              It is another logic. Whether it suits you, you have to decide.
             
              The callbacks have shown up to be a mighty tool, while
              at the same time having a good performance. 
              
             
              A few nonextensive benchmarks show,
              this engine is a bit faster than perl's regular expression machine,
              slower than gnu grep (around factor2), and has the same speed as sed.
              This might vary with each usecase, but the callbacks for extracting matches
              have some advantage, as well as the strict left to right and nongreedy parsing.
             
              In favor of codesize I'm not going to optimize ext_match,
              but there would be several possibilities, if you'd need a faster engine.
              (Albite I'd like to emphasise, sed (and ext_match), also perl, are quite fast.
              About 5 to 10 times faster than most expression engines.)
             
              matches: 
              
              * for every count of any char
              + for 1 or more chars
              ? for 1 char
              # for space, end of text (\0), linebreak, tab
              $ match end of text (\0) or linebreak
             
              backslash: escape *,?,%,$,!,+,#,& and backslash itself.
              !: invert the matching of the next character or character class
              ,: separator. e.g. %,1 matches like ?*1. 
                ( without the commata, the '1' would be part of the % match)
               
             
              predefined character classes:
              \d - digit
              \D - nondigit
              \s - space
              \S - nonspace
              \w - word character ( defined as ascii 32-126,160-255 )
              \W - nonword character ( defined as ascii 0-31,127-159 )
             
             
              [xyz]: character classes, here x,y or z 
                the characters are matched literally, also \,*,?,+,..
                it is not possible to match the closing bracket (])
                within a character class
             
              {nX}: counted match
               Match n times X.
               For X, all expressions are allowed.
               If you need to match a number at the first char of 'X',
               separate X by a commata. E.g. {5,0} matches 5 times '0'.
             
              (X): match the subexpression X. atm, no nesting of round () and {} brackets allowed
             
              %[1]..%[9]: matches like a '+',
               and calls the callback supplied as 3rd argument (when not null).
               the number past the %, e.g. %1, is optional,
               p_match will be callen with this number
               as first parameter.
               When not supplied, p_matched will be callen with 
               the parameter 'number' set to 0.
             
               The matching is 'nongreedy'.
               It is possible to rewrite the string to match
               from within the p_matched callback.
               This will not have an effect onto the current matching,
               even if text is e.g. deleted by writing 0's.
               The matched positions are called in reverse order.
               (The last matched % in the regex calls p_match first, 
               the first % in the regex from the left will be callen last)
               / The regex is first matched; when the regex has matched,
               the %'s are filled/ the callbacks executed.
               (x) bracketed patterns are matched the same way.
             
               (Not like &, which callbacks are invoked, while matching)
             
              supply 0 for p_matched, when you do not need to extract matches.
              This will treat % in the regex like a *, 
              a following digit (0..9) in the regex is ignored.
              if the 5th argument, a pointer to a regex_match struct, 
              is supplied, it will be filled with the first match.
              (counting from left)
             
             
              &[1] .. &[9]
               "match" like a '?' and call p_match_char
               p_match_char has to return either RE_MATCH, RE_NOMATCH, RE_MATCHEND
               or a number of the count of chars, which have been matched.
             
               Therefore it is possible to e.g. rule your own
               character classes, defined at runtime, 
               or do further tricks like changing the matched chars,
               match several chars, andsoon.
               When returning RE_NOMATCH,
               it is possible, the p_match and p_match_char callbacks are callen several times,
               but with different pos or len parameters.
             
               The matching works straight from left to right.
               So, a "*&*" will call the callback & for the first char.
               When returning RE_NOMATCH, the second char will be tried to match.
               Until either RE_MATCH is returned from the callback,
               or the last char of the text has been tried to match.
             
               Matching several characters is also posssible from within the callback,
               the position within the text will be incremented by that number,
               you return from the callback.
             
               When returning RE_MATCHEND from the callback, 
               the whole regular expression is aborted, and returns with matched;
               no matter, if there are chars left in the expression.
             
             
               The difference between % and & is the logic.
               % matches nongreedy, and has to check therefore the right side of the star
               for its matching.
               Possibly this has to be repeated, when following chars do not match.
             
               & is matched straight from left to right.
               Whatever number you return, the textpointer will be incremented by that value.
               However, a & isn't expanded on it's own. ( what a % is ).
               e.g. "x%x" will match 'aa' in xaax, x&x will match the whole expression
               only, when you return '2' from the callback.
             
               Performancewise, matching with & is faster,
               since the % has on its right side to be matched
               with recursing calls of ext_match.
             
              When using closures for the callbacks, you will possibly have to
              enable an executable stack for the trampoline code
              of gcc. Here, gcc complains about that. 
              For setting this bit, please have a look into the ldscripts in the folder
              with the same name.
             
              supply 0 for p_match_char, when you don't need it.
              This will treat & in the regex like ?, 
              and match a following digit (0..9) in the text,
              a following digit (0..9) in the regex is ignored.
              
              -----
              In general, you have to somehow invert the logic of regular expressions
              when using ext_match.
              e.g. when matching the parameter 'runlevel=default' at the kernel's
              commandline, a working regular expression would be
              "runlevel=(\S*)". This could be written here as "*runlevel=%#".
              For matching e.g. numbers, you'd most possibly best of
              with writing your own & callback.
             
              returns: 1 on match, 0 on no match
              ( RE_MATCH / RE_NOMATCH )
             
              if the pointer (argument 5) st_match is nonnull,
              the supplied struct regex_match will be set to the first matching '%' location;
              if there is no match, regex_match.len will be set to 0.
              The struct is defined as: 
              typedef struct _regex_match { char* pos; int len; } regex_match;
             
             
              (memo) When the regex ist defined within C/cpp source code,
              a backslash has to be defined as double backslash.
             
              (note) - be careful when negating a following *, or ?.
               somehow - it is logical, but seems to me I overshoot a bit,
               tragically hit my own foot, and stumbled into a logical paradox.
             
               Negating EVERYTHING translates to true.
               However, since truth is negated as well, there's a problem,
               cause it's now 'false', but 'false' is true. This is very close
               to proving 42 is the answer. What is the escape velocity
               in km/s out of the solar system, btw.
             
               (I'm not kidding here. Just don't do a regex with !* or !?..
               And, please, do not ask me what is going to happen when the impossible
               gets possibilized. I have to point at the according sentences of the BSD license;//  there is NO WARRANTY for CONSEQUENTIAL DAMAGE, LOSS OF PROFIT, etc pp.)
             
               A "!+" will translate into nongreedy matching of any char, however;
               "%!+" will match with % everything but the last char;
               while "%+" matches with % only the first char.
               !+ basically sets the greedyness of the left * or % higher.
             
              (work in progress here) please use ext_match
              return 0 for nomatch, the current textpos ( >0 ) for a match
              With the exception of an empty text, matched by e.g. "*".
              This will return 0, albite the regex formally matches, with 0 chars.
             
              (todo)
              bracket matching () and {} needs debugging. (test/extmatch2 for testing)
              Add a callback for bracket matches, and add a matchlist
              (linked list, allocated with malloc_brk)
              Trouble: e.g. *:(*) doesn't match, albite it should
               .. better. Now: # matches the end, after a bracket. Like it should
                $ doesn't. But should as well.
              change '+' to greedy matching of any char
              for {n,X} let n be * or + as well.
               (this would be closer to regular regulars again.?.)
             
             
              note. About a tokenizer:
              matching quoted string is really easy with the callback structure:
               just match with &. When a quote is matched, look forward to the next quote,
               and return that many chars. Same time, the quoted string is matched.
               That's so easy, it is hard to believe.
               When using closures for that, it is same time easy to collect all tokens.
             
               It is even easier. just a "*("*")*" is enough.
             
               ->There is something needed for partial matching. Possibly spare the last *, and return,
               as soon the pattern is at it's end (and not the text?)
               Already works this way. 
             
               Should start to define the language for the init scripts.
               Or better, start thinking abut that, but follow my other obligations the next time.
             
               Have to think thouroughly about what points would make such a language useful.
               The reason to think about that is clear - performance squeezing, faster startup time.
               And writing the startup scripts in C is. Well. little bit painful.
               However, together with minilib, there is nearly no difference between having a C program compiled
               and run, or working with scripts. To not have the overhead of linking the external libraries in,
               is of quite some advance.
               The only difference, the compiled binaries are "cached".
               have just to sort something sensible out for the systematic.
               Implement an own loader? possibly easy. Since the loading address is fixed.
               This could possibly also be the solution for the yet unclear question of the line between parsing
               arguments and calling the main function of the small core tools, andsoon.
               
               gerad faellt mir "rings" ein. Ist ein idealer Aufreisser, als bootup animation.
               (src/ext_match2.c: 271)

fexecve        static inline int fexecve(int fd, char *const argv[], char *const envp[]);

               (include/fexecve.h: 3)

fexecveat      static inline int fexecveat(int fd, char *const argv[], char *const envp[]);

               (include/fexecveat.h: 3)

fprintfs       int fprintfs( FILE* F, char *fmt, ...);

               prints formatted and unbuffered output to the stream F.
              only %s and %c are recognized.
              no mini_buf or globals are used, so using fprintfs instead of fprintf can save some sections / bytes.
               (src/fprintfs.c: 10)

fprints        #define fprints(F,...) dprints(fileno(F),__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stream
              this macro has an variable argument count.
               (include/prints.h: 33)

free_brk       int free_brk();

               free all memory,
              which has been allocated with malloc_brk.
              Returns 0, if memory has been freed;
              1, when there hasn't been any memory allocations with
              malloc_brk before.
              Then brk() gives an error, return the return value of brk
               (src/freebrk.c: 9)

fwrites        #define fwrites(fd,str) write(fd,str,sizeof(str))

               write the constant str to fd. Computes length with sizeof(str) at compile time.
               (include/prints.h: 94)

getbrk         static long getbrk();

               get the current brk
              does either a syscall to brk,
              or returns the globally saved var
               (src/brk.c: 39)

grantpt        int grantpt(int fd);

               (src/pty.c: 13)

group_print    

               enable print and related functions
              This switch enables strlen;
              but neither globals nor the mini_buf are used.
               (macros/defgroups.h: 13)

group_printf   //

               printf, eprintf, fprintf, itodec and ltodec (conversions %d %l), 
               (macros/defgroups.h: 29)

group_write    

               write, and related functions
              these functions do not depend on strlen, 
              or any globals.
               (macros/defgroups.h: 23)

itobin         #define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

               convert a number to a binary representation.
              the conversion assumes a size of 32bits for integers,
              negative values are represented as they are stored internally.
              ( -1 is 11111111111111111111111111111111,
                -2    11111111111111111111111111111110, ...)
               (src/itobin.c: 46)

itodec         int itodec(int i, char *buf, int prec, char limiter );

               (src/itodec.c: 118)

itooct         int itooct(int i, char *buf);

               convert int to octal
              return the number of chars written.
               (src/itooct.c: 4)

ltodec         int ltodec(long i, char *buf, int prec, char limiter );

               (src/ltodec.c: 75)

malloc_brk     void* malloc_brk(int size);

               allocate via setting the brk
              free and realloc can be used normally.
              The intention of malloc_brk is for subsequent calls to realloc.
              The saved data has not to be copied,
              instead realloc just writes the new size and sets 
              the brk accordingly.
              if the break is saved before one or more calls to malloc_brk,
              the allocated memory can also be free'd by setting the brk to the saved value
              with brk(saved_brk)
              free_brk() free's all memory, which has been allocated with malloc_brk
               (src/malloc_brk.c: 16)

map_protected  void* map_protected(int len);

               allocate a buffer, which is surrounded by protected pages. 
              mprotect(PROT_NONE)
              When there is a buffer overflow,
              neither the stack, nor other structures can be overwritten.
              Instead the overflow (or underflow) touches the next protected page,
              what results in a segfault.
              The size is always a mutliple of the systems pagesize, 4kB here.
              The len of the mapped memory area is rounded up to the next pagesize.
              The mapped area can only be freed by call(s) to munmap,
              neither realloc nor free are allowed.
              There is one page before, and one page after the mapped area
              protected with PROT_NONE, and len rounded up to the next
              pagebreak. So this is the overhead. 
              If an error occures, errno is set (when defined), 
              and -1 returned, or the negative errno value, when errno isn't defined.
               (src/map_protected.c: 19)

match          int match(char *text, const char *re, regex_match *st_match);

               regex engine
              little bit simpler version than ext_match.
              The engine matches nongreedy straight from left to right,
              so backtracking is minimized.
              It is a compromise between performance, size
              and capabilities.
             
              matches: 
              
              * for every count of any char
              + for 1 or more chars
              ? for 1 char
              # for space or end of text (0)
              $ match end of text
             
              backslash: escape *,?,%,!,+,#,$ and backslash itself.
              ! : invert the matching of the next character or character class
               
              [xyz]: character classes, here x,y or z 
                the characters are matched literally, also \,*,?,+,..
                it is not possible to match the closing bracket (])
                within a character class
             
             
              % : matches like a '+', and fills in argument 3,
              the regex_match struct, when the pointer is non null.
              The matching is 'nongreedy'.
             
             
              returns: 1 on match, 0 on no match
              ( RE_MATCH / RE_NOMATCH )
             
              if the pointer (argument 3) st_match is nonnull,
              the supplied struct regex_match will be set to the first matching '%' location;
              if there is no match, regex_match.len will be set to 0.
              The struct is defined as: 
              typedef struct _regex_match { char* pos; int len; } regex_match;
             
             
              (memo) When the regex ist defined within C/cpp source code,
              a backslash has to be defined as double backslash.
             
              (note) - be careful when negating a following *, or ?.
               somehow - it is logical, but seems to me I overshoot a bit,
               and tapped into a logical paradox.
               Negating EVERYTHING translates to true.
               However, since truth is negated as,... well, there's a problem.
             
               (I'm not kidding here. Just don't do a regex with !* or !?.,
               or you might experience the meaning of full featured. 
               Maybe I should say, it's not allowed?)
             
               A "!+" will translate into nongreedy matching of any char, however;
               "%!+" will match with % everything but the last char;
               while "%+" matches with % only the first char.
               !+ basically sets the greedyness of the left * or % higher.
               (src/match.c: 59)

memfrob        void* memfrob(void* s, unsigned int len);

               (src/memfrob.c: 3)

mmap           static void* __attribute__((optimize("O0"))) mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off);

               mmap wrapper
              address length is rounded up to a multiple of pagesize (4096 Bytes here)
              for the description, please look up the according manpage
              errno is only set, when mini_errno is defined
              if not, on error the negative errno value is returned.
              (e.g. -22 for "invalid argument")
               (src/mmap.c: 8)

mremap         static void* volatile __attribute__((optimize("O0"))) mremap(void* addr, size_t old_len, size_t new_len, int flags, void* new_addr);

               (include/mremap.h: 4)

opendirp       static DIR *opendirp(const char *name, DIR *dir);

               (src/dirent/opendir.c: 10)

optimization_fencestatic void __attribute__((noipa,cold)) optimization_fence(void*p);

               prevent optimizations.
              cast a var to void*, and calling this,
              leaves the compiler unknown on what he can strip.
              (noipa) means the compiler doesn't know, what the function itself does.
              (the function does nothing, but don't tell that gcc, please..)
              therefore, everything used as parameter to this function,
              will be calculated, defined, and so on before.
              It's used for the globals, 
              shich are pushed within _start onto the stack.
              since _start itself only provides a global pointer,
              and initialitzes some of the globals,
              but doesn't use them again,
              this construction is needed.
              more funnily, the function will never be called.
              It's past the asm inline syscall to exit.
              But again, luckily gcc doesn't know.
              All other options, like having the globals volatile, 
              setting the optimization flag of _start to 0, 
              having a volatile asm call with the globals as param, and so on,
              have been useless. All after all, seems to me, ai has it's restrictions.
               (include/minilib_global.h: 90)

posix_openpt   int posix_openpt(int flags);

               (src/pty.c: 8)

print          #define print(str) write(STDOUT_FILENO,str,strlen(str))

               write str to stdout. Needs strlen
               (include/prints.h: 54)

printfs        #define printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)

               write fmt and arguments to stdout. 
              only format %s and %c are recognized
               (include/prints.h: 100)

printl         #define printl() write(STDOUT_FILENO,"\n",1)

               write a newline to stdout
               (include/prints.h: 63)

prints         #define prints(...) _mprints(__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stdout,
              this macro has an variable argument count.
               (include/prints.h: 18)

printsl        #define printsl(...) _mprints(__VA_ARGS__,"\n",0)

               print the string(s) supplied as arg(s) and newline to stdout
               (include/prints.h: 41)

ptsname        char *ptsname(int fd);

               (src/pty.c: 43)

ptsname_r      int ptsname_r(int fd, char *buf, size_t len);

               (src/pty.c: 30)

putenv         int putenv( char *string );

               put a string into the environmental vars
              the supplied string's pointer is put into the environmental array of pointers.
              Subsequent changes of the string therefore will change the environment,
              and the supplied string may not be deallocated.
              Returns: 
              - 0 on success, 
              - EINVAL: string was 0, didn't contain a '=', some other error
               (src/putenv.c: 10)

ret_errno      #ifdef mini_errno

               This macro expands to a return, and
              (when mini_errno is defined) returns -1 and sets errno,
              or returns the negative errno value.
               (include/ret_errno.h: 5)

sbrk           static void* sbrk(long incr);

               Set the new brk, increment/decrement by incr bytes.
              return the old brk on success.
              conformant sbrk, when mini_errno is defined
              if no errno is available,
              returns the negative errno value on error
               (src/brk.c: 57)

scandir_bufsize//#define mini_scandir_bufsize 4096

               the increment of the buffer of scandir in bytes for memory allocations
              (default:4096)
               (src/dirent/scandir.c: 4)

sdbm_hash      unsigned long sdbm_hash(const unsigned char *str);

               (src/hashes.c: 21)

seterrno       #ifdef mini_errno

               set errno, but only when errno is defined.
               (include/seterrno.h: 3)

shortcolornames

               short ansi color names
              all colornames, without the praefix "AC_"
               (include/ansicolors.h: 103)

snprintf       int snprintf( char *buf, size_t size, const char *fmt, ... );

               (src/snprintf.c: 5)

swap           static inline void swap(void* a, void* b,int size);

               swap a with b, with 'size' bytes
              swaps integers and longs at once, when size eq sizeof(int/long)
               (src/qsort.c: 31)

sys_brk        static long sys_brk(unsigned long addr);

               the kernel syscall brk.
               (src/brk.c: 6)

uitodec        int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter );

               convert int to string.
              prec: precision, e.g. 4=> 0087 
               (src/itodec.c: 8)

ultodec        int ultodec(unsigned long ui, char *buf, int prec, char limiter );

               (src/ltodec.c: 6)

unlockpt       int unlockpt(int fd);

               (src/pty.c: 23)

unmap_protectedint unmap_protected(void *p, int len);

               (src/map_protected.c: 41)

verbose_errstr const char* verbose_errstr(int num);

               verbose error (errno) string. 
              this adds about 3.5kB to the compiled binary(!)
               (include/errstr.h: 8)

verbose_errstr2static const char* verbose_errstr2(int num);

               verbose error (errno) string. 
              this adds about 3.5kB to the compiled binary(!)
              Trying to shrink that here.
               (include/errstr2.h: 11)

vexec          int vexec( const char* path, char* const* argv, char* const* envp );

               execute a path, wait until the executed file exits.
              Deviating of system() an absolute pathname is taken.
              sets errno on error.
               (src/vexec.c: 6)

vexec_q        int vexec_q( const char* path, char* const* argv, char* const* envp );

               execute a path, wait until the executed file exits, 
              do not write any output of the process. (close stdout)
              Deviating of system() an absolute pathname is taken.
               (src/vexec.c: 30)

vsnprintf      int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

               the function, translating the fmt of printf.
              warning - most possibly you'd like to define besides fprintf, or family,
              mini_itodec (%d conversion) 
              mini_atoi is needed for grouping numbers
               (src/sprintf.c: 43)

writes         #define writes(str) write(STDOUT_FILENO,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 84)



==========
mini_syscalls
==========

sys__sysctl       
sys_accept        
sys_accept4       
sys_access        
sys_acct          
sys_add_key       
sys_adjtimex      
sys_alarm         
sys_arch_prctl    
sys_bind          
sys_capget        
sys_capset        
sys_chdir         
sys_chmod         
sys_chown         
sys_chroot        
sys_clock_adjtime 
sys_clock_getres  
sys_clock_gettime 
sys_clock_nanosleep
sys_clock_settime 
sys_clone         
sys_close         
sys_connect       
sys_creat         
sys_delete_module 
sys_dup           
sys_dup2          
sys_dup3          
sys_epoll_create  
sys_epoll_create1 
sys_epoll_ctl     
sys_epoll_pwait   
sys_epoll_wait    
sys_eventfd       
sys_eventfd2      
sys_execve        
sys_exit          
sys_exit_group    
sys_faccessat     
sys_fadvise64     
sys_fallocate     
sys_fanotify_init 
sys_fanotify_mark 
sys_fchdir        
sys_fchmod        
sys_fchmodat      
sys_fchown        
sys_fchownat      
sys_fcntl         
sys_fdatasync     
sys_fgetxattr     
sys_finit_module  
sys_flistxattr    
sys_flock         
sys_fork          
sys_fremovexattr  
sys_fsetxattr     
sys_fstat         
sys_fstatfs       
sys_fsync         
sys_ftruncate     
sys_futex         
sys_futimesat     
sys_get_mempolicy 
sys_get_robust_list
sys_getcpu        
sys_getcwd        
sys_getdents      
sys_getdents64    
sys_getegid       
sys_geteuid       
sys_getgid        
sys_getgroups     
sys_getitimer     
sys_getpeername   
sys_getpgid       
sys_getpgrp       
sys_getpid        
sys_getppid       
sys_getpriority   
sys_getrandom     
sys_getresgid     
sys_getresuid     
sys_getrlimit     
sys_getrusage     
sys_getsid        
sys_getsockname   
sys_getsockopt    
sys_gettid        
sys_gettimeofday  
sys_getuid        
sys_getxattr      
sys_init_module   
sys_inotify_add_watch
sys_inotify_init  
sys_inotify_init1 
sys_inotify_rm_watch
sys_io_cancel     
sys_io_destroy    
sys_io_getevents  
sys_io_setup      
sys_io_submit     
sys_ioctl         
sys_ioperm        
sys_iopl          
sys_ioprio_get    
sys_ioprio_set    
sys_kcmp          
sys_kexec_file_load
sys_kexec_load    
sys_keyctl        
sys_kill          
sys_lchown        
sys_lgetxattr     
sys_link          
sys_linkat        
sys_listen        
sys_listxattr     
sys_llistxattr    
sys_lookup_dcookie
sys_lremovexattr  
sys_lseek         
sys_lsetxattr     
sys_lstat         
sys_madvise       
sys_mbind         
sys_memfd_create  
sys_migrate_pages 
sys_mincore       
sys_mkdir         
sys_mkdirat       
sys_mknod         
sys_mknodat       
sys_mlock         
sys_mlockall      
sys_mmap          
sys_modify_ldt    
sys_mount         
sys_move_pages    
sys_mprotect      
sys_mq_getsetattr 
sys_mq_notify     
sys_mq_open       
sys_mq_timedreceive
sys_mq_timedsend  
sys_mq_unlink     
sys_mremap        
sys_msgctl        
sys_msgget        
sys_msgrcv        
sys_msgsnd        
sys_msync         
sys_munlock       
sys_munlockall    
sys_munmap        
sys_name_to_handle_at
sys_nanosleep     
sys_newfstatat    
sys_open          
sys_open_by_handle_at
sys_openat        
sys_pause         
sys_perf_event_open
sys_personality   
sys_pipe          
sys_pipe2         
sys_pivot_root    
sys_poll          
sys_ppoll         
sys_prctl         
sys_pread64       
sys_preadv        
sys_prlimit64     
sys_process_vm_readv
sys_process_vm_writev
sys_pselect6      
sys_ptrace        
sys_pwrite64      
sys_pwritev       
sys_quotactl      
sys_read          
sys_readahead     
sys_readlink      
sys_readlinkat    
sys_readv         
sys_reboot        
sys_recvfrom      
sys_recvmmsg      
sys_recvmsg       
sys_remap_file_pages
sys_removexattr   
sys_rename        
sys_renameat      
sys_renameat2     
sys_request_key   
sys_restart_syscall
sys_rmdir         
sys_rt_sigaction  
sys_rt_sigpending 
sys_rt_sigprocmask
sys_rt_sigqueueinfo
sys_rt_sigreturn  
sys_rt_sigsuspend 
sys_rt_sigtimedwait
sys_rt_tgsigqueueinfo
sys_sched_get_priority_max
sys_sched_get_priority_min
sys_sched_getaffinity
sys_sched_getattr 
sys_sched_getparam
sys_sched_getscheduler
sys_sched_rr_get_interval
sys_sched_setaffinity
sys_sched_setattr 
sys_sched_setparam
sys_sched_setscheduler
sys_sched_yield   
sys_seccomp       
sys_select        
sys_semctl        
sys_semget        
sys_semop         
sys_semtimedop    
sys_sendfile      
sys_sendmmsg      
sys_sendmsg       
sys_sendto        
sys_set_mempolicy 
sys_set_robust_list
sys_set_tid_address
sys_setdomainname 
sys_setfsgid      
sys_setfsuid      
sys_setgid        
sys_setgroups     
sys_sethostname   
sys_setitimer     
sys_setns         
sys_setpgid       
sys_setpriority   
sys_setregid      
sys_setresgid     
sys_setresuid     
sys_setreuid      
sys_setrlimit     
sys_setsid        
sys_setsockopt    
sys_settimeofday  
sys_setuid        
sys_setxattr      
sys_shmat         
sys_shmctl        
sys_shmdt         
sys_shmget        
sys_shutdown      
sys_sigaltstack   
sys_signalfd      
sys_signalfd4     
sys_socket        
sys_socketpair    
sys_splice        
sys_stat          
sys_statfs        
sys_swapoff       
sys_swapon        
sys_symlink       
sys_symlinkat     
sys_sync          
sys_sync_file_range
sys_syncfs        
sys_sysfs         
sys_sysinfo       
sys_syslog        
sys_tee           
sys_tgkill        
sys_time          
sys_timer_create  
sys_timer_delete  
sys_timer_getoverrun
sys_timer_gettime 
sys_timer_settime 
sys_timerfd_create
sys_timerfd_gettime
sys_timerfd_settime
sys_times         
sys_tkill         
sys_truncate      
sys_umask         
sys_umount2       
sys_uname         
sys_unlink        
sys_unlinkat      
sys_unshare       
sys_ustat         
sys_utime         
sys_utimensat     
sys_utimes        
sys_vfork         
sys_vhangup       
sys_vmsplice      
sys_wait4         
sys_waitid        
sys_write         
sys_writev        


==========
signal.h
==========

raise          static inline int raise(int signr);

               (src/sigaction.c: 135)

sigaction      static int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact);

               (src/sigaction.c: 107)

sigaddset      int sigaddset(sigset_t *set, int sig);

               (src/sigaction.c: 34)

sigdelset      int sigdelset(sigset_t *set, int sig);

               (src/sigaction.c: 58)

sigemptyset    static int sigemptyset(sigset_t *set);

               (src/sigaction.c: 7)

sigfillset     static int sigfillset(sigset_t *set);

               (src/sigaction.c: 20)

sigismember    int sigismember(sigset_t *set, int sig);

               (src/sigaction.c: 75)

signal         sighandler_t signal(int sig, sighandler_t func );

               (src/signal.c: 5)

sigprocmask    int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

               (src/sigaction.c: 52)



==========
stdio.h
==========

_fopen         FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f);

               modes implemented: r, r+, w, w+, a, a+
               (src/_fopen.c: 12)

_itohex        int _itohex(int i,char* buf,int padding, int capitals);

               (src/itohex.c: 6)

clearerr       static inline void clearerr(FILE *f);

               (include/mini_fstream.h: 184)

clearerror     static inline void clearerror(FILE *f);

               (include/mini_fstream.h: 189)

fclose         static inline int __attribute__((always_inline)) fclose( FILE* f );

               (include/mini_fstream.h: 65)

fdopen         FILE *fdopen(int fd, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 20)

feof           static inline int feof(FILE *f);

               (include/mini_fstream.h: 170)

ferror         static inline int ferror(FILE *f);

               (include/mini_fstream.h: 177)

fflush         static inline int __attribute__((always_inline)) fflush( FILE *F );

               This does nothing, since minilib doesn't provide buffered streams yet.In order to sync data to disc, please use fsync
               (include/mini_fstream.h: 28)

fgetc          static inline int fgetc(FILE *F);

               (include/fgetc.h: 11)

fgetpos        static inline void fgetpos(FILE *f, long *pos );

               (include/mini_fstream.h: 113)

fgets          char* fgets(char *buf, int size, FILE* F);

               (src/fgets.c: 4)

fileno         static int fileno( FILE *f );

               Return the fd nummber of stdin,-out,-err. 
               (include/mini_fstream.h: 56)

fopen          FILE *fopen(const char* filename, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 10)

fprint         #define fprint(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 81)

fprintf        #define fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,sprintf(mlgl->mbuf,__VA_ARGS__))

               fprintf, formatted output
              conversions implemented:
              %d: signed int
              %u: unsigned int
              %f: double (max precision 8 digits, highest possible number: 2^31
              %l (modify a following d,u to long)
              %s: string
              %c: char
              %b : binary output
              %x/X : hex output (small/big capitals)
              %(: grouping
             
              For squeezing a few more bytes, and saving some checking;
              writes(constant string) and print (variable string) are provided.
             
              
               (src/sprintf.c: 249)

fputc          static inline int volatile fputc(int c, FILE* F);

               (include/fputc.h: 10)

fputs          static inline int volatile fputs(const char *c, FILE *F);

               (include/fputs.h: 20)

fread          static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 148)

freopen        FILE *freopen(const char* filename, const char* mode, FILE *F);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 30)

fseek          static inline int fseek(FILE *f, long offset, int whence );

               (include/mini_fstream.h: 132)

fsetpos        static inline int fsetpos(FILE *f, int pos );

               (include/mini_fstream.h: 119)

ftell          static inline long ftell(FILE *f);

               (include/mini_fstream.h: 107)

fwrite         static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 92)

getc           #define getc(F) fgetc(F)

               (include/fgetc.h: 26)

getchar        #define getchar() fgetc(0)

               (include/fgetc.h: 29)

gets           #define gets(F) fgets(F,0xfffffff,stdin)

               (src/fgets.c: 27)

itoHEX         int itoHEX(int i,char* buf,int padding);

               convert a number to hexadecimal representation with big capitals.
              the conversion assumes a size of 32bits for integers,
              negative values are represented as they are stored internally.
              ( -1 is 0xFFFFFFFF, -2 0xFFFFFFFE, ... )
               (src/itohex.c: 65)

itohex         int itohex(int i,char* buf,int padding);

               convert a number to hexadecimal representation.
              the conversion assumes a size of 32bits for integers,
              negative values are represented as they are stored internally.
              ( -1 is 0xffffffff, -2 0xfffffffe, ... )
               (src/itohex.c: 53)

perror         void perror(const char *msg);

               (src/perror.c: 4)

printf         #define printf(...) fprintf(stdout,__VA_ARGS__)

               (include/mini_fstream.h: 77)

putc           #define putc(c,stream) fputc(c,stream)

               (include/fputc.h: 19)

putchar        #define putchar(c) fputc(c,stdout)

               (include/fputc.h: 16)

puts           #define puts(msg) ( print(msg) + printl() )

               write msg to stdout, append a newline. Needs strlen.
               (include/prints.h: 73)

rewind         static inline void rewind( FILE *f );

               (include/mini_fstream.h: 142)

setbuf         static void setbuf(FILE *stream, char *buf);

               dummy function.
              There is no buffering implemented for the streams yet.
               (include/mini_fstream.h: 197)

setvbuf        static int setvbuf(FILE *stream, char *buf, int mode, size_t size);

               dummy function
               (include/mini_fstream.h: 202)

sprintf        #define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

               (src/sprintf.c: 26)

ungetc         static int ungetc(int c, FILE *F);

               pushes one char back to the stream.
              Overwrites a previously pushed char
              (conforming to the posix spec) 
               (include/fgetc.h: 35)

vfprintf       #define vfprintf(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 86)

vsprintf       int vsprintf( char *buf, const char *fmt, ... );

               write fmt and arguments into buf
              calls vsnprintf, 
              the size is limited to 4096 by default.
               (src/vsprintf.c: 9)



==========
stdlib.h
==========

abort          void abort();

               (src/abort.c: 3)

abs            static int abs(int i);

               (include/math.h: 25)

atexit         static int atexit( functionp* func );

               register functions, which are callen on exit in reverse order
              the switch mini_atexit takes a optional number,
              which defines the maximum numbers of functions to be registered.
              (defaults to 8)
               (src/atexit.c: 7)

atoi           int atoi(const char *c);

               (src/atoi.c: 3)

atol           long atol(const char *c);

               (src/atol.c: 3)

div            static div_t div(int numerator, int denominator);

               (include/math.h: 8)

free           void free(void *p);

               (src/malloc.c: 146)

getenv         char* getenv(const char* name);

               (src/getenv.c: 8)

labs           static long int labs(long int i);

               (include/math.h: 30)

ldiv           static ldiv_t ldiv(long int numerator, long int denominator);

               (include/math.h: 16)

malloc         void* malloc(int size);

               0
              Here we go.. with the .. well. 
              Fastes and smallest malloc/free combi ever. 
              Not the smartest.
              Since it isn't exactly a memory allocation,
              instead it (mis)uses the minilib buf.
              Which is allocated by the kernel, and uses
              either the bss section, or is allocated on the stack.
              (option "globals_on_stack")
             
              This is basically a linked list,
              optimized for fast access, allocation of new elements, 
              and small memory overhead.
              Albite the list structure might be hard to recognize.
              It is not the right malloc, if you expect
              many de- or reallocations.
              And it obviously is not the right choose, when
              expecting medium to big sized allocations. (> 1 page, here 4kB, as medium sized)
              
              Here we use mbuf from top to bottom as stack.
              64 Bytes are left at the bottom as reserve.
              Possibly we'd like to complain
              about the lack of memory, before we exit.
             
              ATM, the 'free' is really lazy. 
              It free's memory, but a real 'free' is only commited,
              when all memory below a freed area is also freed.
              Since the target of minilib atm are tiny tools, 
              this might be ok.
              ;) but, as I told before - 
              probably you should look out for a proper malloc implementation.
              It depends on your needs.
             
              I'm not sure yet, 
              whether another implementation of free would be useful at all.
              Overall, I'd really prefer keeping minilib tiny.
             
              Reusing sparse freed memory areas also leads 
              to a whole bunch of complications.
              cache misses, searching complexity,
              storage overhead, potentially page faults,
              just to name a few.
             
              I'm not sure whether it's worth it.
             
              And the existing malloc implementations 
              out there are countless.
             
              ;) It's sometimes smarter to stay special,
              albite in this case this means the opposite.
              /misc
             
              The memory layout looks like this:
              mlgl->ibuf and mlgl->mbuf do point to the same address range.
              mlgl->ibuf is provided for alignment and faster access to the int values.
             
              flag prev free is the first bit in size. (0x8000, eq 1000 0000 0000 0000 binary when free), 
              (mbufsize)
              ```
                   size  data  size    mini_buf size
                   8008dataxxxx0004data8000|
                   ----========----====----|
             
              also, when free space is in between two areas
              
              8004data8008  free  0004data8000|
              ----====----________----====----|
             
              ```
              the free space is only freed, 
              when all areas below (left) have been free'd as well.
             
              Memory is allocated from right to left, 
              meaning from top to down.
               (src/malloc.c: 126)

qsort          void qsort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *));

               (quick) shell sort routine
              following the tradition, this isn't exactly a quicksort algorithm,
              albite named quicksort.
              It is a shell sort implementation, originally done by Ray Gardner, 5/90;
              which in turn I did find within musl.
               (src/qsort.c: 57)

rand           unsigned int rand();

               (src/rand.c: 15)

realloc        void* realloc(void *p, int size);

               (src/malloc.c: 210)

srand          void srand( unsigned int i );

               (src/rand.c: 7)

strtol         long int strtol(const char *c, const char **endp, int base);

               conversion
              doesn't check for overflow(!)
               (src/strtol.c: 5)

system         int system( const char* command );

               (src/system.c: 4)



==========
string.h
==========

_strcasecmp    int _strcasecmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 27)

_strcmp        int _strcmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 10)

memcmp         int memcmp(const void* c1,const void* c2,int len);

               (src/strcmp.c: 84)

memcpy         void *memcpy( void *d, const void *s, int n );

               (src/memcpy.c: 4)

memmove        void* memmove(void *dest, const void *src, int n);

               (src/memmove.c: 3)

memset         void *memset( void *s, int c, int n);

               (src/memset.c: 3)

strcasecmp     int strcasecmp(const char*c1,const char*c2);

               (src/strcmp.c: 48)

strcat         char *strcat(char *dest, const char *src );

               (src/strcat.c: 5)

strchr         char *strchr(const char *s, int c);

               (src/strchr.c: 20)

strchrnul      char *strchrnul(const char *s, int c);

               (src/strchr.c: 7)

strcmp         int strcmp(const char*c1,const char*c2);

               (src/strcmp.c: 67)

strcpy         char *strcpy(char *dest, const char *src);

               (src/strcpy.c: 3)

strdup         char *strdup(const char *source);

               (src/strdup.c: 7)

strerror       static char* strerror( int errnum );

               (src/strerror.c: 7)

strlen         int strlen(const char*str);

               (src/strlen.c: 4)

strncasecmp    int strncasecmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 56)

strncmp        int strncmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 75)

strncpy        char *strncpy(char *dest, const char *src, int n);

               (src/strncpy.c: 4)

strrchr        char *strrchr(const char *s, int c);

               (src/strchr.c: 36)

strstr         char* strstr(const char *big, const char *little);

               (src/strstr.c: 3)



==========
sys/wait.h
==========

wait           pid_t wait(int *wstatus);

               (src/wait.c: 8)

waitpid        pid_t waitpid(pid_t pid, int *wstatus, int options);

               (src/wait.c: 16)



==========
time.h
==========



==========
unistd.h
==========

execl          static int execl(const char *pathname, const char* arg0,... );

               (src/execl.c: 6)

execv          static inline int execv(const char *pathname, char *const argv[]);

               (src/execvp.c: 9)

execvp         static inline int execvp(const char *file, char *const argv[]);

               (src/execvp.c: 58)

execvpe        static int execvpe(const char *file, char *const argv[], char *const envp[]);

               When invoked with a filename, starting with "." or "/",
              interprets this as absolute path. (calls execve with the pathname)
              Looks for file in the PATH environment, othwerise.
               (src/execvp.c: 18)

isatty         int isatty(int fd);

               (src/isatty.c: 5)

open           int volatile open( const char *s, int flags, ... );

               open or create a file.
              warning: when using the flag O_CREAT,
              file permission flags have to be given
              as third argument. Otherwise file permission
              flags will be random. (I still do not know, what 
              the flag showing up as "-T" means..)
               (src/open.c: 19)

select         static int volatile __attribute__((optimize("O0"))) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);

               (include/select.h: 9)

sleep          unsigned int volatile sleep(unsigned int seconds);

               nonconformant sleep
              TODO: ignore blocked signals, sigchld
               (src/sleep.c: 10)

tcgetattr      static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

               (include/tcgetattr.h: 21)

tcsetattr      static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

               (include/tcsetattr.h: 20)

usleep         unsigned int volatile usleep(unsigned int useconds);

               nonconformant usleep. 
              Sleep useconds.
              I just hope, noone relies on an exact sleep time.
              which isn't possible without a real time os, anyways.
              When for whatever reason you'd need nanoseconds exact times,
              best shot might be a spinloop, and looking for cpu ticks.
             
              TODO: ignore blocked signals, sigchld
               (src/sleep.c: 31)

