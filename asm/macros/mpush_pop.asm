.ifndef mpush_pop_included
mpush_pop_included:

.macro mpush args:vararg
.irp iter,\args
push \iter
.endr
.endm

.macro mpop cur, args:vararg
.ifnb \args
mpop \args
.endif
pop  \cur
.endm

.macro mpushrev cur, args:vararg
.ifnb \args
mpushrev \args
.endif
push  \cur
.endm

.macro mpoprev args:vararg
.irp iter,\args
pop \iter
.endr
.endm

.endif
