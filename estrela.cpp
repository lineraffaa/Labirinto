#include <iostream>
#include <iomanip>
#define TAM 100
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct No
{
    int x, y;
    float f, g, h;
    int paiX, paiY;
};

void estrela(float matriz[TAM][TAM], int iniciox, int inicioy, int fimx, int fimy)
{
    vector<No> listaaberta;

    bool listafechada[TAM][TAM] = {false};

    No inicial = {iniciox, inicioy, 0, 0, 0, -1, -1};
    inicial.h = abs(iniciox - fimx) + abs(inicioy - fimy);
    inicial.f = inicial.g + inicial.h;
    listaaberta.push_back(inicial);

    int paix[TAM][TAM];
    int paiy[TAM][TAM];
    


    //! para representar as direções é utilizado dois vetores 
    int direx[] = {-1,1,0,0}, direy[] = {0,0,-1,1};
    

    while (!listaaberta.empty())
    {
        int idx = 0;
        for (int i = 0; i < listaaberta.size(); i++)
        {
            if (listaaberta[i].f < listaaberta[idx].f)
            {
                idx = i;
            }
        }
        No atual = listaaberta[idx];

        listaaberta.erase(listaaberta.begin() + idx);

        listafechada[atual.x][atual.y] = true;

        paix[atual.x][atual.y] = atual.paiX;

        paiy[atual.x][atual.y] = atual.paiY;


           cout <<fimx << fimy;

        if (atual.x == fimx && atual.y == fimy)
        {
            int endx = fimx;
            int endy = fimy;
         
            while (endx != -1 && endy != -1)
            {
                    
                 cout << "(" << endx << ", " << endy << ")" << endl;
                int px = paix[endx][endy];
                int py = paiy[endx][endy];
                endx = px;
                endy = py;

                
            }
            break;


        }

        for(int j = 0; j < 4; j++){
            int coorx, coory; 
            coorx = atual.x + direx[j]; 
            coory = atual.y + direy[j];
            
            if(coorx < 0 || coorx >= TAM || coory < 0 || coory >= TAM) continue;

           if(matriz[coorx][coory] == 1) continue;
            if(listafechada[coorx][coory]) continue;

            float novoG = atual.g + 1;
            float novoH = abs(coorx - fimx) + abs(coory - fimy);
            float novoF = novoG + novoH;

            No vizinho = {coorx, coory, novoF, novoG, novoH, atual.x, atual.y};
            listaaberta.push_back(vizinho);
        
        }
        

    }


   

}

int main()
{

    float matriz[TAM][TAM];

    srand(time(NULL));

    // Preenchendo a matriz
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {

            matriz[i][j] = rand() % 2;
        }
    }
    matriz[0][0] = 0;
    matriz[TAM-1][TAM-1] = 0;
    cout << "AQQ";
   estrela(matriz, 0, 0, TAM - 1, TAM - 1);
}