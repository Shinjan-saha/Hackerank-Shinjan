char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

void get_word(char** text, int start, int end, int* word_count, char*** words) {
    char* tmp = calloc(end - start, sizeof(char));
    strncat(tmp, *text + start, end - start);

    (*word_count)++;
    *words = realloc(*words, *word_count * sizeof(char*));
    (*words)[*word_count - 1] = tmp;
}

void get_sentence(char**** sentences, int* sentence_count, char*** words, int* word_count) {
    (*sentence_count)++;
    *sentences = realloc(*sentences, *sentence_count * sizeof(char**));
    (*sentences)[*sentence_count - 1] = *words;

    *words = calloc(1, sizeof(char*));
    *word_count = 0;
}

void get_paragraph(char***** paragraphs, int* paragraph_count, char**** sentences, int* sentence_count) {
    (*paragraph_count)++;
    *paragraphs = realloc(*paragraphs, *paragraph_count * sizeof(char***));
    (*paragraphs)[*paragraph_count - 1] = *sentences;

    *sentences = calloc(1, sizeof(char**));
    *sentence_count = 0;
}

// A document is
//     an array of paragraphs (separated by '\n'), which is
//         an array of sentences (separated by '.'), which is
//             an array of words (separated by ' '), which is
//                 an array of characters
char**** get_document(char* text) {
    char** words = calloc(1, sizeof(char*));
    char*** sentences = calloc(1, sizeof(char**));
    char**** paragraphs = calloc(1, sizeof(char***));

    int pos = 0, last_pos = 0, word_count = 0, sentence_count = 0, paragraph_count = 0;
    while (pos < strlen(text)) {
        if (text[pos] == ' ' || text[pos] == '.' || text[pos] == '\n') {
            get_word(&text, last_pos, pos, &word_count, &words);
            last_pos = pos + 1;

            if (text[pos] == '.' || text[pos] == '\n') {
                get_sentence(&sentences, &sentence_count, &words, &word_count);
            }

            if (text[pos] == '\n') {
                get_paragraph(&paragraphs, &paragraph_count, &sentences, &sentence_count);
            }
        }

        pos++;
    }
    get_paragraph(&paragraphs, &paragraph_count, &sentences, &sentence_count);

    return paragraphs;
}
