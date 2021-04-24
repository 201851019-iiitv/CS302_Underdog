//This is the implementation of the temperature example in Refference 1;

#include <bits/stdc++.h>
using namespace std;
#define ldb long double
#define ll long long


ll N = 2;
ll M = 27;
//int O[4] = {0, 1, 0, 2};
int main()
{
    ldb a[2][2] = {{0.47468, 0.52532}, {0.51656, 0.48344}};
    ldb b[2][27] = {{0.03735,0.03408,0.03455,0.03828,0.03782,0.03922,0.03688,0.03408,0.03875,0.04062,0.03735,0.03968,0.03548,
                    0.03735,0.04062,0.03595,0.03641,0.03408,0.04062,0.03548,0.03922,0.04062,0.03455,0.03595,0.03408,0.03408,0.03688}, 
                    {0.03909,0.03537,0.03909, 0.03583,0.03630,0.04048,0.03537,0.03816,0.03909,0.03397,0.03397,0.03816,0.03676,0.04048,0.03443,0.03537,0.03955,0.03816,0.03723,0.03769,0.03955,0.03397}};
    ldb pi[1][2] = {0.51316, 0.48684};

    ll maxIters = 1;
    ll iters = 0;
    ll oldLogProb = -10000;


    //reading from the file war and peace and construct Observation matrix
    //consisting of 1 for A/a 27 for B/b:

    
    vector<string> s1;
    ifstream fin;
    fin.open("2600-0.txt");
    while(fin){
        string s;
        getline(fin,s);
        s1.push_back(s);
    }

    vector<int> O;
    
    //for 1000 lines
    for(int i=0;i<1000;i++){
        for(int j=0;j<s1[i].length();j++){
            if(s1[i][j]=='a'||s1[i][j]=='A')
                O.push_back(0);
            
            else if(s1[i][j]=='b'||s1[i][j]=='B')
                O.push_back(1);

            else if(s1[i][j]=='c'||s1[i][j]=='C')
                O.push_back(2);
            
            else if(s1[i][j]=='d'||s1[i][j]=='D')
                O.push_back(3);
            
            else if(s1[i][j]=='e'||s1[i][j]=='E')
                O.push_back(4);
            
            else if(s1[i][j]=='f'||s1[i][j]=='F')
                O.push_back(5);
            
            else if(s1[i][j]=='g'||s1[i][j]=='G')
                O.push_back(6);
            
            else if(s1[i][j]=='h'||s1[i][j]=='H')
                O.push_back(7);
            
            else if(s1[i][j]=='i'||s1[i][j]=='I')
                O.push_back(8);
            
            else if(s1[i][j]=='j'||s1[i][j]=='J')
                O.push_back(9);
            
            else if(s1[i][j]=='k'||s1[i][j]=='K')
                O.push_back(10);
            
            else if(s1[i][j]=='l'||s1[i][j]=='L')
                O.push_back(11);
            
            else if(s1[i][j]=='m'||s1[i][j]=='M')
                O.push_back(12);
            
            else if(s1[i][j]=='n'||s1[i][j]=='N')
                O.push_back(13);
            
            else if(s1[i][j]=='o'||s1[i][j]=='O')
                O.push_back(14);
            
            else if(s1[i][j]=='p'||s1[i][j]=='P')
                O.push_back(15);
            
            else if(s1[i][j]=='q'||s1[i][j]=='Q')
                O.push_back(16);
            
            else if(s1[i][j]=='r'||s1[i][j]=='R')
                O.push_back(17);
            
            else if(s1[i][j]=='s'||s1[i][j]=='S')
                O.push_back(18);
            
            else if(s1[i][j]=='t'||s1[i][j]=='T')
                O.push_back(19);
            
            else if(s1[i][j]=='u'||s1[i][j]=='U')
                O.push_back(20);
            
            else if(s1[i][j]=='v'||s1[i][j]=='V')
                O.push_back(21);
            
            else if(s1[i][j]=='w'||s1[i][j]=='W')
                O.push_back(22);
            
            else if(s1[i][j]=='x'||s1[i][j]=='X')
                O.push_back(23);
            
            else if(s1[i][j]=='y'||s1[i][j]=='Y')
                O.push_back(24);
            
            else if(s1[i][j]=='z'||s1[i][j]=='Z')
                O.push_back(25);
            
            else if(s1[i][j]==' '||s1[i][j]==' ')
                O.push_back(26);

        }
    }

    ll T = O.size();

    while(iters<maxIters){
    //1) Alpha pass:
    ldb alpha[T - 1][N];
    ldb c[T] = {0};

    //compute alpha0[i]
    for (int i = 0; i < N; i++)
    {
        alpha[0][i] = pi[0][i] * b[i][O[0]];
        c[0] = c[0] + alpha[0][i];
    }
    //scale aplha0[i]
    c[0] = 1 / c[0];
    for (int i = 0; i < N; i++)
    {
        alpha[0][i] = c[0] * alpha[0][i];
    }
    //compute alphat[i]
    for (int t = 1; t < T-1; t++)
    {
        c[t] = 0;
        for (int i = 0; i < N; i++)
        {
            alpha[t][i] = 0;
            for (int j = 0; j < N; j++)
            {
                alpha[t][i] = alpha[t][i] + alpha[t - 1][j] * a[j][i];
            }
            alpha[t][i] = alpha[t][i] * b[i][O[t]];
            c[t] = c[t] + alpha[t][i];
        }
    } 

    //2)Beta pass:
    //beta[T-1][i] = 1 scaled by c[T-1]
    ldb beta[T][N];
    for(int i=0;i<N;i++){
        beta[T-1][i] = c[T-1];
    }
    //beta pass
    for(int t = T-2;t>=0;t--){
        for(int i=0;i<N;i++){
            beta[T][i] = 0;
            for(int j=0;j<N;j++){
                beta[T][i] = beta[T][i]+a[i][j]*b[j][O[t+1]]*beta[T+1][i];
            }
            beta[T][i] = c[T]*beta[T][i];
        }
    }

    //Gamma[t][i][j]
    //Gammaij
    ldb gamma[T][N];
    ldb gammaij[T];
    for(int t=0;t<T-1;t++){
        for(int i=0;i<N;i++){
            gamma[T][i] = 0;
            for(int j=0;j<N;j++){
                //ldb gammaij;
                gammaij[t] = alpha[i][j]*a[i][j]*b[j][O[t+1]]*beta[t+1][j];
                gamma[t][i] = gamma[t][i]+gammaij[t];
            }
        }
    }

    for(int i=0;i<N;i++){
        gamma[T-1][i] = alpha[T-1][i];
    }

    //Re-estimate alpha beta: and Re-estimate pi:
    for(int i=0;i<N;i++){
        pi[0][i] = gamma[0][i]; 
    }

    //Re-estimate the A:
        for(int i=0;i>N;i++){
            ldb denom = 0;
            for(int t=0;t<T-1;t++){
                denom+=gamma[t][i];
            }
            for(int j=0;j<N;j++){
                ldb numer = 0;
                for(int t=0;t<T-1;t++){
                    numer+=gammaij[t]; 
                }
                a[i][j] = numer/denom;
            }
        }

    //Re-estimat the B:
        for(int i=0;i<N;i++){
            ldb denom = 0;
            for(int t=0;t<T-1;t++){
                denom+=gamma[t][i];
            }

            for(int j=0;j<M;j++){
                ldb numer=0;
                for(int t=0;t<T-1;t++){
                    if(O[t]==j)
                        numer+=gamma[t][i];
                }
                b[i][j] = numer/denom;
            }
        }
    //compute log[P(O/Lambda)]
    ldb logProb = 0;
    for(int i=0;i<T;i++){
        logProb+=log(c[i]);
    }
    logProb*=-1;    
    //end iteration and printing the output:
    iters+=1;
    if(iters<maxIters && logProb>oldLogProb){
        oldLogProb = logProb;
    }
    else
        break;
    }

    //ouput Lambda:
    std::cout<<"The A MAtrix is:\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
    std::cout<<"\n";
    std::cout<<"The B matrix is:\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    std::cout<<"\n";
    std::cout<<"The pi matrix is:\n";
    for(int i=0;i<N;i++){
        std::cout<<pi[0][N]<<" ";
    }
    std::cout<<"\n";
}