package main

import (
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
)

func usage() {
	fmt.Printf("Usage: go run [solution number]\n")
	os.Exit(1)
}

func copy(src, dst string) (int64, error) {
	sourceFileStat, err := os.Stat(src)
	if err != nil {
		return 0, err
	}

	if !sourceFileStat.Mode().IsRegular() {
		return 0, fmt.Errorf("%s is not a regular file", src)
	}

	source, err := os.Open(src)
	if err != nil {
		return 0, err
	}
	defer source.Close()

	destination, err := os.Create(dst)
	if err != nil {
		return 0, err
	}
	defer destination.Close()
	nBytes, err := io.Copy(destination, source)
	return nBytes, err
}

func main() {
	if len(os.Args) != 2 {
		usage()
	}

	number, err := strconv.Atoi(os.Args[1])
	if err != nil {
		usage()
	}
	fmt.Printf(" %d\n", number)

	var dirname string
	if number < 100 {
		dirname = "001"
	} else {
		dirname = strconv.Itoa((number / 100) * 100)
	}
	dirname = dirname + "/" + strconv.Itoa(number)
	fmt.Printf(" %s\n", dirname)

	fi, err := os.Lstat("./")
	if err != nil {
		log.Fatal(err)
	}
	os.MkdirAll(dirname, fi.Mode().Perm()&os.ModePerm)

	files := [2]string{"main.cpp", "Makefile"}
	tempale_dir := "./template"
	for _, file := range files {
		copy(tempale_dir+"/"+file, dirname+"/"+file)
	}
}
