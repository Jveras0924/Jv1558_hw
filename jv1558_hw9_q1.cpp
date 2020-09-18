

#include <iostream>
#include <string>
using namespace std;

void letterAndWordCount(string lineOfText);// get word and letter count

int main(){

    string lineOfText;

    cout << "Please enter a line of text: " << endl;
    getline(cin, lineOfText);

    letterAndWordCount(lineOfText);

    return 0;
}

void letterAndWordCount(string lineOfText){
    //initialize int vars for each letter
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0;
    int q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z =0;

    int wordCount = 0, count;
    char space = ' ', period = '.', comma = ',';
    char character;


    for(count = 0; count < lineOfText.length(); count += 1){
        character = lineOfText[count];
        if(character == space || character == period || character == comma) {
            wordCount += 1;
            if(character == space && lineOfText[count - 1] == comma)
                wordCount -= 1;
            if(character == space && lineOfText[count - 1] == period)
                wordCount -= 1;
        }
        else if(character == 'a' || character == 'A')
            a += 1;
        else if(character == 'b' || character == 'B')
            b += 1;
        else if(character == 'c' || character == 'C')
            c += 1;
        else if(character == 'd' || character == 'D')
            d += 1;
        else if(character == 'e' || character == 'E')
            e += 1;
        else if(character == 'f' || character == 'F')
            f += 1;
        else if(character == 'g' || character == 'G')
            g += 1;
        else if(character == 'h' || character == 'H')
            h += 1;
        else if(character == 'i' || character == 'I')
            i += 1;
        else if(character == 'j' || character == 'J')
            j += 1;
        else if(character == 'k' || character == 'K')
            k += 1;
        else if(character == 'l' || character == 'L')
            l += 1;
        else if(character == 'm' || character == 'M')
            m += 1;
        else if(character == 'n' || character == 'N')
            n += 1;
        else if(character == 'o' || character == 'O')
            o += 1;
        else if(character == 'p' || character == 'P')
            p += 1;
        else if(character == 'q' || character == 'Q')
            q += 1;
        else if(character == 'r' || character == 'R')
            r += 1;
        else if(character == 's' || character == 'S')
            s += 1;
        else if(character == 't' || character == 'T')
            t += 1;
        else if(character == 'u' || character == 'U')
            u += 1;
        else if(character == 'v' || character == 'V')
            v += 1;
        else if(character == 'w' || character == 'W')
            w += 1;
        else if(character == 'x' || character == 'X')
            x += 1;
        else if(character == 'y' || character == 'Y')
            y += 1;
        else if(character == 'z' || character == 'Z')
            z += 1;
    }

    // (in a loop)count a letter add it to letter total until end of word then count the word, repeat until end of string

    cout << wordCount << "     words" << endl;
    if(a > 0)
        cout << a << "      a" << endl;
    if(b > 0)
        cout << b << "      b" << endl;
    if(c > 0)
        cout << c << "      c" << endl;
    if(d > 0)
        cout << d << "      d" << endl;
    if(e > 0)
        cout << e << "      e" << endl;
    if(f > 0)
        cout << f << "      f" << endl;
    if(g > 0)
        cout << g << "      g" << endl;
    if(h > 0)
        cout << h << "      h" << endl;
    if(i > 0)
        cout << i << "      i" << endl;
    if(j > 0)
        cout << j << "      j" << endl;
    if(k > 0)
        cout << k << "      k" << endl;
    if(l > 0)
        cout << l << "      l" << endl;
    if(m > 0)
        cout << m << "      m" << endl;
    if(n > 0)
        cout << n << "      n" << endl;
    if(o > 0)
        cout << o << "      o" << endl;
    if(p > 0)
        cout << p << "      p" << endl;
    if(q > 0)
        cout << q << "      q" << endl;
    if(r > 0)
        cout << r << "      r" << endl;
    if(s > 0)
        cout << s << "      s" << endl;
    if(t > 0)
        cout << t << "      t" << endl;
    if(u > 0)
        cout << u << "      u" << endl;
    if(v > 0)
        cout << v << "      v" << endl;
    if(w > 0)
        cout << w << "      w" << endl;
    if(x > 0)
        cout << x << "      x" << endl;
    if(y > 0)
        cout << y << "      y" << endl;
    if(z > 0)
        cout << z << "      z" << endl;
    //output number of words and the word words
    //output only letter that appear  > 0 in string and then the letter

}
