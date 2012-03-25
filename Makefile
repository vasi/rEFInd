# Makefile for rEFInd
CC=gcc
CXX=g++
CXXFLAGS=-O2 -fpic -D_REENTRANT -D_GNU_SOURCE -Wall -g
NAMES=prefit
SRCS=$(NAMES:=.c)
OBJS=$(NAMES:=.o)
HEADERS=$(NAMES:=.h)
LOADER_DIR=refind
LIB_DIR=libeg

# Build the Symbiote library itself.
all:
	make -C $(LIB_DIR) -j 6
	make -C $(LOADER_DIR) -j 6

clean:
	make -C $(LIB_DIR) clean
	make -C $(LOADER_DIR) clean
# DO NOT DELETE
