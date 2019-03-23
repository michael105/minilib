// This is "callen" just before main.
// 
// dbg("Startup -xx"); // no arguments allowed here. 
// otherwise argv[] gets confused
// Or we would have to add some further bloating bytes
#ifdef mini_buf
ml.mbufsize = mini_buf;
#endif
