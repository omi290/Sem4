#include <stdio.h>

void findMaxOccurrence(int n, char arr[]) {
    int freq[26] = {0};
    
    for (int i = 0; i < n; i++) {
        freq[arr[i] - 'a']++;
    }

    int maxFreq = 0;
    char maxChar = '\0';

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }

    if (maxFreq == 1) {
        printf("No Duplicates Present\n");
    } else {
        printf("%c %d\n", maxChar, maxFreq);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        char arr[n];

        for (int i = 0; i < n; i++) {
            scanf(" %c", &arr[i]);
        }

        findMaxOccurrence(n, arr);
    }

    return 0;
}
