int minFlips(int a, int b, int c) {
        int k = 0;
        while(a || b || c){
            int x = a & 1;
            int y = b & 1;
            int z = c & 1;
            if((x | y) != z){
                if(x & y){
                    k += 2;
                }
                else{
                    k += 1;
                }
            }
            a >>= 1, b >>= 1, c >>= 1;
        }

        return k;
    }
