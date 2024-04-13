#include <iostream>
#include "tokenizer.hpp"
#include <string>
#include <vector>

using namespace std;

int main() {
    //TRIE_TOKENIZER tokenizer("hextest_vocab.txt");
    TRIE_TOKENIZER tokenizer("../rwkv_vocab_v20230424.txt");
    // multi line string:
    auto stringtoencode = R"(Q: System with two quadratic equations Respected All.
I am unable to find out what's so wrong in the following. Please help me.
It is given that $t$ is a common root of the following two equations given by 
egin{align}
&x^2-bx+d=0    ag{1}\
&ax^2-cx+e=0   ag{2}
\end{align}
where $a,b,c,d,e$ are real numbers. 
Then using cross multiplication technique, we shall get
$$
  rac{t^2}{cd-be}=
                  rac{t}{ad-e}=
                               rac{1}{ab-c}   ag{3}$$
which will give us $$tegin{cases}

rac{cd-be}{ad-e},\

rac{ad-e}{ab-c},\
\pm\sqrt{
         rac{cd-be}{ab-c}}
\end{cases}    ag{I}$$
My problems starts from here. If $t$ satisfies both (1) and (2) then any linear combination of (1) and (2) should be satisfied by $t$. So that by $\lambda  imes (1)+\mu        imes (2)$ we shall have 
$$(\lambda+\mu a)t^2-(\lambda b+\mu c)t+(\lambda d+\mu e)=0     ag{4}$$
where $\lambda, \mu$ are suitable reals for (4) to have real roots.
hence we shall get 
$$t=
    rac{1}{2(\lambda+\mu a)}[(\lambda b+\mu c)\pm \sqrt{(\lambda b+\mu c)^2-4(\lambda+\mu a)(\lambda d+\mu e)}]     ag{II}$$
All three results in (I) and the results in (II) are supposed to be same. Aren't they?
So what if we consider $(a,b,c,d,e)=(3,9,38,14,119)$. Then from (I) we shall get $(7,7,7)$. But when we shall apply (II) then the results are becoming "dirty": if we choose $\lambda=-16,\mu=20$ the results are coming as $(7.057474264\cdots, 7.06\cdots)$
Why is it happening ? Am I making any theoratical mistake?

A: We have two polynomial equations $f_1(x)=f_2(x)=0$ with quadratic polynomials
$f_1(x)=x^2-bx+d$ and $f_2(x)=ax^2-cx+e$, where $a,b,c,d,e$ are the coefficients.
Then 
$$
t=
  rac{ \pm \sqrt{b^2 - 4d} + b}{2}
$$ 
is a common root, if and only if the coefficients satisfy certain poylnomial conditions. 
To see this, just substitute this to the second equation.
We can make a case distinction. Assume that $d=0$. Then $t=b$ is a common root for $b
eq 0$ if $a=
            rac{bc - e}{b^2}$, and $c,e$ arbitrary; and for $b=0$ if $e=0$ and $a,b,c$ arbitrary. 
If $d
eq 0$, $t=
          rac{ \sqrt{b^2 - 4d} + b}{2}$ is a common root if and only if
$$
a=
  rac{\sqrt{b^2 - 4d}\cdot be - \sqrt{b^2 - 4d}\cdot cd - b^2e + bcd + 2de}{2d^2}.
$$
A very similar formula holds for the case $t=-
                                              rac{ \sqrt{b^2 - 4d} + b}{2}$. 
For your example  $(a,b,c,d,e)=(3,9,38,14,119)$ the formula gives $t=7$. We have $\sqrt{b^2-4d}=5$, so that $t=
                                                                                                               rac{ \sqrt{b^2 - 4d} + b}{2}=7$, and the relation between $a,b,c,d,e$ is satisfied.
Edit: For your example $(a,b,c,d,e)=(3,9,38,14,119)$ your equation II gives the solutions $t=7$ and $t=(2\lambda + 17\mu)/(\lambda + 3\mu)$. For $\lambda=-16$ and $\mu=20$ I obtain exactly $t=7$, so no problem. I suppose you have done a computational mistake there.)";

    auto encoded = tokenizer.encode(stringtoencode);
    auto decoded = tokenizer.decode(encoded);
    cout << decoded << endl;


    std::vector<std::string> strings = {stringtoencode, stringtoencode, stringtoencode};
    auto encodedBatch = tokenizer.encodeBatch(strings);
    for (auto i : encodedBatch) {
        for (auto j : i) {
            cout << (int)j << " ";
        }
        cout << endl;
    }


    //tokenizer.testStringToBytes("hello world");
    // auto encoded = tokenizer.encode("⠁ ⠙⠕");
    // for (auto i : encoded) {
    //     cout << (int)i << " ";
    // }
    // cout << endl;
    // auto decoded = tokenizer.decode(encoded);
    // cout << decoded << endl;

    // //tokenizer.testStringToBytes("результарезульта");
    // encoded = tokenizer.encode("Now that the Mount Tabor reservoirs no longer hold our drinking water, can we pee and/or swim in them? âCaptain Billy");
    
    // for (auto i : encoded) {
    //     cout << (int)i << " ";
    // }
    // cout << endl;
    // decoded = tokenizer.decode(encoded);
    // cout << decoded << endl;

    // encoded = tokenizer.encode("A week into Movember, how's your moustache coming along?\n\nA week into Movember, how's your moustache coming along?");
    // for (auto i : encoded) {
    //     cout << (int)i << " ";
    // }
    // cout << endl;
    // decoded = tokenizer.decode(encoded);
    // cout << decoded << endl;

    // //tokenizer.testStringToBytes("hello\n world");

    // encoded = tokenizer.encode("გთხოვთ ახლავე გაიაროთ რეგისტრაცია Unicode-ის მეათე საერთაშორისო");
    // for (auto i : encoded) {
    //     cout << (int)i << " ";
    // }
    // cout << endl;
    // decoded = tokenizer.decode(encoded);
    // cout << decoded << " ";
    // cout << endl;


    // encoded = tokenizer.encode("⠁ ⠙⠕⠕⠗⠤⠝⠁⠊⠇⠲ ⡊ ⠍⠊⠣⠞ ⠙⠁⠧⠑ ⠃⠑⠲ ⠔⠊⠇⠔⠫⠂ ⠍⠹⠎⠑⠇⠋⠂ ⠞⠕");
    // for (auto i : encoded) {
    //     cout << (int)i << " ";
    // }
    // cout << endl;
    // decoded = tokenizer.decode(encoded);
    // cout << decoded << " ";
    // cout << endl;
//     cout << endl;
//     decoded = tokenizer.decode(encoded);
//     for (auto i : decoded) {
//         cout << i;
//     }
//     cout << endl;


//     encoded = tokenizer.encode(R"(A week into Movember,
// how's your moustache coming along? In case you're not aware of the hair-growing event taking place this month, Movember is the initiative that raises funds for men's health charities. Normally clean-shaven men are encouraged to avoid the upper lip with the razor and grow a moustache whilst fund-raising from friends, family, and colleagues.)");
//     for (auto i : encoded) {
//         cout << i << " ";
//     }
//     cout << endl;
//     decoded = tokenizer.decode(encoded);
//     for (auto i : decoded) {
//         cout << i;
//     }
//     cout << endl;


    return 0;
}