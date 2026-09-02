//Encontra x e y tais que: a * x + b * y = gcd(a, b)
int extgcd(int a, int b, int &x, int &y) {
    if (b==0){
        x = 1;y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int modInverso(int a, int m) {
    int x, y;
    int g = extgcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}
