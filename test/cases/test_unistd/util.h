#include <utest.h>

#include <unistd.h>
#include <getopt.h>


#define OPTION_END               -1
#define OPTIONS_UNKNOWN         '?'
#define OPTION_MISS             ':'
#define DECLARE_ARGS(...)                       \
    optind = 1;                                 \
    char * argv[] = {__FILE__, __VA_ARGS__};    \
    int argc = sizeof(argv) / sizeof(char*);    \

/*
* According To System V Doc for getopt
*
* The variable optind is the index of the next element to be processed in argv. 
* The system initializes this value to 1.   
* The caller can reset it to 1 to restart scanning of the same argv, 
* or when scanning a new argument vector.
*/
SUB_TEST_CASE(unistd_getopt){
BEGIN_DECL
    // initial value
    EXPECT_EQ(optind, 1);
    EXPECT_EQ(opterr, 1);
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-g");
    EXPECT_EQ(argc, 2);
    EXPECT_EQ(getopt(argc, argv, "g"), 'g');
    EXPECT_EQ(getopt(argc, argv, "g"), OPTION_END);
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(optopt, NULL);
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-g", "true");
    EXPECT_EQ(argc, 3);
    EXPECT_EQ(getopt(argc, argv, "g:"), 'g');
    EXPECT_NE(optarg, NULL);
    EXPECT_STR_EQ(optarg, "true");
    EXPECT_EQ(optind, 3);
    EXPECT_EQ(getopt(argc, argv, "g:"), OPTION_END);
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-g", "true", "-c", "hello", "-o");
    EXPECT_EQ(getopt(argc, argv, "g:c:o"), 'g');
    EXPECT_NE(optarg, NULL);
    EXPECT_STR_EQ(optarg, "true");
    EXPECT_EQ(optind, 3);
    EXPECT_EQ(getopt(argc, argv, "g:c:o"), 'c');
    EXPECT_NE(optarg, NULL);
    EXPECT_STR_EQ(optarg, "hello");
    EXPECT_EQ(optind, 5);
END_DECL
BEGIN_DECL
    opterr = 0;
    DECLARE_ARGS("-h");
    EXPECT_EQ(getopt(argc, argv, "o"), OPTIONS_UNKNOWN);
    EXPECT_EQ(optarg, NULL);
    EXPECT_NE(optopt, NULL);
    EXPECT_EQ(optopt, 'h');
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(getopt(argc, argv, "o"), OPTION_END);
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-h", "false");
    EXPECT_EQ(getopt(argc, argv, "h"), 'h');
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(getopt(argc, argv, "h"), OPTION_END);
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-h");
    EXPECT_EQ(getopt(argc, argv, "h:"), OPTIONS_UNKNOWN);
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optopt, 'h');
END_DECL
BEGIN_DECL
// if optstring star with : then if missing argument the return value 
// will be : otherwise the return value will be ?
    DECLARE_ARGS("-h");
    EXPECT_EQ(getopt(argc, argv, ":h:"), OPTION_MISS);
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optopt, 'h');
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-a", "-c", "hello.c", "-o", "hello.o", "-g", "-h");
    const char * needed = ":ac:o:g";
    EXPECT_EQ(getopt(argc, argv, needed), 'a');
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(getopt(argc, argv, needed), 'c');
    EXPECT_EQ(optind, 4);
    EXPECT_NE(optarg, NULL);
    EXPECT_STR_EQ(optarg, "hello.c");
    EXPECT_EQ(getopt(argc, argv, needed), 'o');
    EXPECT_EQ(optind, 6);
    EXPECT_NE(optarg, NULL);
    EXPECT_STR_EQ(optarg, "hello.o");
    EXPECT_EQ(getopt(argc, argv, needed), 'g');
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optind, 7);
    EXPECT_EQ(getopt(argc, argv, needed), OPTIONS_UNKNOWN);
    EXPECT_EQ(getopt(argc, argv, needed), OPTION_END);
END_DECL
BEGIN_DECL
    // if the option need one argument but not support it may 
    // misuse the wrong argument
    DECLARE_ARGS("-a", "-c", "-o", "hello.o", "-g", "-h");
    const char * needed = ":ac:o:g";
    EXPECT_EQ(getopt(argc, argv, needed), 'a');
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(getopt(argc, argv, needed), 'c');
    EXPECT_EQ(optind, 4);
    EXPECT_NE(optarg, NULL);
    EXPECT_STR_EQ(optarg, "-o");
    EXPECT_EQ(getopt(argc, argv, needed), 'g');
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optind, 6);
    EXPECT_EQ(getopt(argc, argv, needed), OPTIONS_UNKNOWN);
END_DECL
BEGIN_DECL
    DECLARE_ARGS("-d");
    EXPECT_EQ(getopt(argc, argv, ":d:"), OPTION_MISS);
    EXPECT_EQ(optind, 2);
    EXPECT_EQ(optarg, NULL);
    EXPECT_EQ(optopt, 'd');
END_DECL
BEGIN_DECL
    // getopt don't support options which start with --
    DECLARE_ARGS("--d");
    EXPECT_EQ(getopt(argc, argv, "d"), OPTIONS_UNKNOWN);
END_DECL
}

SUB_TEST_CASE(unistd_getopt_long){
    EXPECT_EQ(no_argument, 0);
    EXPECT_EQ(required_argument, 1);
    EXPECT_EQ(optional_argument, 2);
}