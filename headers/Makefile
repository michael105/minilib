SUBDIRS=common linux_x64

all:
	@$(foreach DIR, $(SUBDIRS), \
			(echo "make $(DIR)/allheaders.h" && \
			cd $(DIR) && \
			echo "#ifndef $(DIR)_allheaders_h" > allheaders.h && \
			echo "#define $(DIR)_allheaders_h" >> allheaders.h	&& \
			find -type f | \
			sed '/allheaders.h/d;s/.*/#include "&"/' >> allheaders.h && \
			echo "#endif" >> allheaders.h ) && ) true

