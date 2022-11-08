
    int j= 0;
    int d;
    for(i = 0; i<n; i++){
        for(j = 1; j<n; j++){
            if((p+j-1)->result < (p+j)->result) {
                d = (p+j-1)->result;
                (p+j-1)->result = (p+j)->result;
                (p+j)->result = d;
            }
        }
    }