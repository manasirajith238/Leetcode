char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = (char*)malloc(strlen(strs[0]) + 1);

    strcpy(prefix, strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }

        prefix[j] = '\0';

        // If no common prefix
        if (strlen(prefix) == 0)
            return "";
    }

    return prefix;

}