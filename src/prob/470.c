 int rand10() {
    int crt = 41;
    while(crt > 40 )crt = (rand7() -1) * 7 + rand7();
    return (crt-1) % 10 +1;
}
