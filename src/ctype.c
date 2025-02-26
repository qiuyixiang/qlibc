/**
 *  MIT License
 *
 *  Copyright (c) 2025 QIU YIXIANG
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

// Implementation of C ctype functions
#define LOWER_START     0x61
#define UPPER_START     0x41
#define DIGIT_START     0x30

// isspace -> isblank 
int isblank(int ch){
    return ((unsigned)ch == 0x09) || ((unsigned)ch == 0x20);
}
int isspace(int ch){
    return isblank(ch) || (((unsigned)ch - 0x0a) < 4);
}
/**
 *  The Implementation Hierarchy of C Character Type function
 *                         islower
 *             isalpha -> 
 * isalnum  ->             isupper
 *             isdigit
 */
int islower(int ch){
    return (((unsigned)ch - LOWER_START) < 26);
}
int isupper(int ch){
    return (((unsigned)ch - UPPER_START) < 26);
}
int isalpha(int ch){
    return islower(ch) || isupper(ch);
}
int isdigit(int ch){
    return (((unsigned)ch - DIGIT_START) < 10);
}
int isalnum(int ch){
    return isalpha(ch) || isdigit(ch);
}
int isxdigit(int ch){
    return isdigit(ch) || (((unsigned)ch | 32) - LOWER_START < 6);
}

// isprint -> isgraph
int isgraph(int ch){
    return ((unsigned)ch >= 0x21) && ((unsigned)ch <= 0x7e);
}
int isprint(int ch){
    return isgraph(ch) || ((unsigned)ch == 0x20);
}

int iscntrl(int ch){
    return ((unsigned)ch < 0x20) || ((unsigned)ch == 0x7f);
}
int ispunct(int ch){
    return isgraph(ch) && !isalnum(ch);
}
// The only difference between upper and lower letter is the 6-th bits
int tolower(int ch){
    if (isupper(ch))
        return (unsigned)ch | 32;
    return ch;
}
int toupper(int ch){
    if (islower(ch))
        return (unsigned)ch ^ 32;
    return ch;
}