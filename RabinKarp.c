#include <stdio.h>
#include <string.h>

void findPattern(char * string, char * pattern, int q);

int main(int argc, char const *argv[]) {
    findPattern("fafafafa", "fa", 29);
    return 0;
}

void findPattern(char * string, char * pattern, int q) {
    const int d = 256;

    int n = strlen(string);
    int m = strlen(pattern);

    int h = 1;
    int p = 0;
    int t = 0;

    for(int i = 1; i < m; i++) {
        h = (h * d) % q;
    }

    //Compute hash for pattern
    for(int i = 0; i < m; i++) {
        p = (p * d + (int) pattern[i]) % q;
    }

    //Compute hash for text
    for(int i = 0; i < m; i++) {
        t = (t * d + (int) string[i]) % q;
    }

    for(int i = 0; i <= n-m; i++) {
        if(t == p) {
            int j;
            for(j = 0; j < m; j++) {
                if(pattern[j] != string[i+j]) break;
            }

            if(j == m) printf("%s %d\n", "Pattern found at index: ", i);
        }

        //Recalculate the hash of next window of text
        if(i != n-m) {
            t = ((t - (h * string[i])) * d + string[i+m]) % q;
            if(t < 0) t += q;
        }
    }
}
