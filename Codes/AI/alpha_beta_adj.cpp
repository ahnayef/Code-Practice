#include<bits/stdc++.h>
using namespace std;

int alphaBeta(int nodeIndex, bool isMax, vector<int> &values,
              vector<vector<bool>> &adjMatrix, int n,
              int alpha, int beta)
{
    bool isLeaf = true;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[nodeIndex][i]) {
            isLeaf = false;
            break;
        }
    }
    
    if (isLeaf)
        return values[nodeIndex];
        
    if (isMax) {
        int best = -1000;
        
        for (int i = 0; i < n; i++) {
            if (adjMatrix[nodeIndex][i]) {
                int val = alphaBeta(i, false, values, adjMatrix, n, alpha, beta);
                best = max(best, val);
                alpha = max(alpha, best);
                
                if (beta <= alpha)
                    break; 
            }
        }
        return best;
    }
    else {
        int best = 1000;
        
        for (int i = 0; i < n; i++) {
            if (adjMatrix[nodeIndex][i]) {
                int val = alphaBeta(i, true, values, adjMatrix, n, alpha, beta);
                best = min(best, val);
                beta = min(beta, best);
                
                if (beta <= alpha)
                    break;
            }
        }
        return best;
    }
}

int main()
{
    int n = 33;  
    
    vector<int> values(n, 0);  
    
    // Set leaf node values
    values[19] = 5;   
    values[20] = 6;   
    values[21] = 7;   
    values[22] = 4;   
    values[23] = 5;   
    values[24] = 3;   
    values[25] = 6;   
    values[26] = 6;   
    values[27] = 9;   
    values[28] = 7;   
    values[29] = 5;   
    values[30] = 9;   
    values[31] = 8;   
    values[32] = 6;   
    
    // Initialize adjacency matrix (n×n)
    vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));
    
    // Format: adjMatrix[parent][child] = true
    
    adjMatrix[0][1] = true;
    adjMatrix[0][2] = true;
    adjMatrix[0][3] = true;
    
    adjMatrix[1][4] = true;
    adjMatrix[1][5] = true;
    
    adjMatrix[2][6] = true;
    adjMatrix[2][7] = true;
    
    adjMatrix[3][8] = true;
    adjMatrix[3][9] = true;
    
    adjMatrix[4][10] = true;
    adjMatrix[4][11] = true;
    
    adjMatrix[5][12] = true;
    
    adjMatrix[6][13] = true;
    adjMatrix[6][14] = true;
    
    adjMatrix[7][15] = true;
    
    adjMatrix[8][16] = true;
    
    adjMatrix[9][17] = true;
    adjMatrix[9][18] = true;
    
    adjMatrix[10][19] = true;
    adjMatrix[10][20] = true;
    
    adjMatrix[11][21] = true;
    adjMatrix[11][22] = true;
    adjMatrix[11][23] = true;
    
    adjMatrix[12][24] = true;
    
    adjMatrix[13][25] = true;
    
    adjMatrix[14][26] = true;
    adjMatrix[14][27] = true;
    
    adjMatrix[15][28] = true;
    
    adjMatrix[16][29] = true;
    
    adjMatrix[17][30] = true;
    adjMatrix[17][31] = true;
    
    adjMatrix[18][32] = true;
    
    int alpha = -1000, beta = 1000;
    
    int optimalValue = alphaBeta(0, true, values, adjMatrix, n, alpha, beta);
    
    cout << "Optimal value using Alpha-Beta Pruning: " << optimalValue << endl;
    return 0;
}