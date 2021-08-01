#!/bin/sh



function conf(){
		echo conf: $*
}

function endconfig(){
		echo endconfig
}

function match(){
		echo match: $*
}

function endfile(){
		echo endfile
}

source $1

