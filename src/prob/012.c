char* intToRoman(int num) {
    if (num == 0)
        return NULL;

    int i = 0,
        floor_digit[4] = {0},
        expence[10] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2},
        expence_total = 0;

    for (int digits = 0; digits < 4; digits++)
    {
        floor_digit[digits] = num % 10;
        num /= 10;
        expence_total += expence[floor_digit[digits]];
    }

    char *result = (char *)malloc(expence_total + 1);
    for(int digits=3;digits>=0;digits--){
		switch(digits){
				case 3:
					switch(floor_digit[digits]){
						case 3:result[i++]='M';
						case 2:result[i++]='M';
						case 1:result[i++]='M';break;
					}
					break;
				case 2:
					switch(floor_digit[digits]){
						case 3:result[i++]='C';
						case 2:result[i++]='C';
						case 1:result[i++]='C';break;
						case 4:result[i++]='C';result[i++]='D';break;
						case 5:result[i++]='D';break;
						case 8:result[i++]='D';result[i++]='C';result[i++]='C';result[i++]='C';break;
						case 7:result[i++]='D';result[i++]='C';result[i++]='C';break;
						case 6:result[i++]='D';result[i++]='C';break;
						case 9:result[i++]='C';result[i++]='M';break;
					}
					break;
				case 1:
					switch(floor_digit[digits]){
						case 3:result[i++]='X';
						case 2:result[i++]='X';
						case 1:result[i++]='X';break;
						case 4:result[i++]='X';result[i++]='L';break;
						case 5:result[i++]='L';break;
						case 8:result[i++]='L';result[i++]='X';result[i++]='X';result[i++]='X';break;
						case 7:result[i++]='L';result[i++]='X';result[i++]='X';break;
						case 6:result[i++]='L';result[i++]='X';break;
						case 9:result[i++]='X';result[i++]='C';break;
					}
					break;
				case 0:
					switch(floor_digit[digits]){
						case 3:result[i++]='I';
						case 2:result[i++]='I';
						case 1:result[i++]='I';break;
						case 4:result[i++]='I';result[i++]='V';break;
						case 5:result[i++]='V';break;
						case 8:result[i++]='V';result[i++]='I';result[i++]='I';result[i++]='I';break;
						case 7:result[i++]='V';result[i++]='I';result[i++]='I';break;
						case 6:result[i++]='V';result[i++]='I';break;
						case 9:result[i++]='I';result[i++]='X';break;
					}
		}
	}
	result[i]='\0';

	return result;
}
