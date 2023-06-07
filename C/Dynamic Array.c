int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    total_number_of_books = (int *)malloc(sizeof(int)*total_number_of_shelves);
    total_number_of_pages = (int **)malloc(sizeof(int *)*total_number_of_shelves);
    for(int i = 0; i<total_number_of_shelves; i++){
                *(total_number_of_books + i) = 0;}
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            int booksInShelf = *(total_number_of_books + x);
            *(total_number_of_pages + x) = (int*)realloc(*(total_number_of_pages+x),sizeof(int)*(booksInShelf+1));
            *(*(total_number_of_pages+x)+booksInShelf) = y;
            *(total_number_of_books + x) += 1;

        }
