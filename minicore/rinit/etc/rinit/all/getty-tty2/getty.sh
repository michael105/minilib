
# get path

DIR=$0
if [ "${DIR#*getty-}" = "$DIR" ]
then 
		DIR=`pwd`
fi

P=${DIR%/run}

# get ttyX part
TTY=${P#*getty-}


