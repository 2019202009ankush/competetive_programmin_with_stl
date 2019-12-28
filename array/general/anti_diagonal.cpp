/*Find Anti Diagonal
  Written By:ANkush Mitra
  Date:25.12.19 Time:16.23*/
  vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
      int n = A.size();
      vector<vector<int>> diag(2*n-1);
      for(int r=0; r<n; r++){
          for(int c=0; c<n; c++){
              diag[r+c].push_back(A[r][c]);
          }
      }
      return diag;
  }
