
#include <iostream>
#include <string>
using namespace std;

void checkAnagram(string lineOfText1, string lineOfText2);
int main(){

    string lineOfText1, lineOfText2;

    cout << "Please input a line of text: " << endl;
    getline(cin, lineOfText1);

    cout << "Please input a second line of text: " << endl;
    getline(cin, lineOfText2);

    checkAnagram(lineOfText1, lineOfText2);

    return 0;
}
void checkAnagram(string lineOfText1, string lineOfText2){

    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0;
    int q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z =0;
    string joinedText = "";
    int count, letterCount = 0;
    char letter;
    bool aT = true, bT = true, cT = true, dT = true, eT = true , fT = true, gT = true, hT = true, iT = true, jT = true;
    bool kT = true, lT = true, mT = true, nT = true, oT = true, pT = true, qT = true, rT = true, sT = true, tT =true;
    bool uT = true, vT = true, wT = true, xT = true, yT = true, zT = true;

    joinedText = lineOfText1 + lineOfText2;

    for(count = 0; count <= joinedText.length(); count += 1){
        letter = joinedText[count];
        if(letter == 'a' || letter == 'A') {
            a += 1;
        }
        else if(letter == 'b' || letter == 'B') {
            b += 1;
        }
        else if(letter == 'c' || letter == 'C') {
            c += 1;
        }
        else if(letter == 'd' || letter == 'D'){
            d += 1;
        }
        else if(letter == 'e' || letter == 'E'){
            e += 1;
        }
        else if(letter == 'f' || letter == 'F'){
            f += 1;
        }
        else if(letter == 'g' || letter == 'G'){
            g += 1;
        }
        else if(letter == 'h' || letter == 'H'){
            h += 1;
        }
        else if(letter == 'i' || letter == 'I'){
            i += 1;
        }
        else if(letter == 'j' || letter == 'J'){
            j += 1;
        }
        else if(letter == 'k' || letter == 'K'){
            k += 1;
        }
        else if(letter == 'l' || letter == 'L'){
            l += 1;
        }
        else if(letter == 'm' || letter == 'M'){
            m += 1;
        }
        else if(letter == 'n' || letter == 'N'){
            n += 1;
        }
        else if(letter == 'o' || letter == 'O'){
            o += 1;
        }
        else if(letter == 'p' || letter == 'P'){
            p += 1;
        }
        else if(letter == 'q' || letter == 'Q'){
            q += 1;
        }
        else if(letter == 'r' || letter == 'R'){
            r += 1;
        }
        else if(letter == 's' || letter == 'S'){
            s += 1;
        }
        else if(letter == 't' || letter == 'T'){
            t += 1;
        }
        else if(letter == 'u' || letter == 'U'){
            u += 1;
        }
        else if(letter == 'v' || letter == 'V'){
            v += 1;
        }
        else if(letter == 'w' || letter == 'W'){
            w += 1;
        }
        else if(letter == 'x' || letter == 'X'){
            x += 1;
        }
        else if(letter == 'y' || letter == 'Y'){
            y += 1;
        }
        else if(letter == 'z' || letter == 'Z'){
            z += 1;
        }
    }
    if(a % 2 != 0)
        aT = false;
    if(b % 2 != 0)
        bT = false;
    if(c % 2 != 0)
        cT = false;
    if(d % 2 != 0)
        dT = false;
    if(e % 2 != 0)
        eT = false;
    if(f % 2 != 0)
        fT = false;
    if(g % 2 != 0)
        gT = false;
    if(h % 2 != 0)
        hT = false;
    if(i % 2 != 0)
        iT = false;
    if(j % 2 != 0)
        jT = false;
    if(k % 2 != 0)
        kT = false;
    if(l % 2 != 0)
        lT = false;
    if(m % 2 != 0)
        mT = false;
    if(n % 2 != 0)
        nT = false;
    if(o % 2 != 0)
        oT = false;
    if(p % 2 != 0)
        pT = false;
    if(q % 2 != 0)
        qT = false;
    if(r % 2 != 0)
        rT = false;
    if(s % 2 != 0)
        sT = false;
    if(t % 2 != 0)
        tT = false;
    if(u % 2 != 0)
        uT = false;
    if(v % 2 != 0)
        vT = false;
    if(w % 2 != 0)
        wT = false;
    if(x % 2 != 0)
        xT = false;
    if(y % 2 != 0)
        yT = false;
    if(z % 2 != 0)
        zT = false;

    if(aT == true && bT == true && cT == true && dT == true && eT == true && fT == true && gT == true && hT == true &&
    iT == true && jT == true && kT == true && lT == true && mT == true && nT == true && oT == true && pT == true &&
    qT == true && rT == true && sT == true && tT == true && uT == true && vT == true && wT == true && xT == true &&
    yT == true && zT == true)
        cout << "These two strings are anagrams.";
    else
        cout << "These two strings are not anagrams.";

}
