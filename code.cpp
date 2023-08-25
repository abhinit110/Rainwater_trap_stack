int trap(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        int res=0,bl=0;
         for(int i=n-1;i>=0;i--)
    {
      
      if (st.empty()) {
        st.push(i);
      }
      else
      {
        if (arr[i] <= arr[st.top()]) {
          st.push(i);
        } else {
          bl=0;
          while (!st.empty()) {
            if (arr[st.top()] < arr[i])
              {
                  st.pop();
              }
            else {
              for(int j=i+1;j<st.top();j++)
              {
                bl+=arr[j];
                arr[j]=arr[i];
              }
              res+=(arr[i]*(st.top()-i-1))-bl;
              st.push(i);
              break;
            }
          }
          if (st.empty()) {
            st.push(i);
          }
        }
      }
      
    }
    cout<<res<<endl;
    while(!st.empty())
    st.pop();
    for(int i=0;i<n;i++)
    {
      
      if (st.empty()) {
        st.push(i);
      }
      else
      {
        if (arr[i] <= arr[st.top()]) {
          st.push(i);
        } else {
          bl=0;
          while (!st.empty()) {
            if (arr[st.top()] < arr[i])
              {
                  st.pop();
              }
            else {
              for(int j=st.top()+1;j<i;j++)
              {
                bl+=arr[j];
                arr[j]=arr[i];
              }
              res+=(arr[i]*(i-st.top()-1))-bl;
              st.push(i);
              break;
            }
          }
          if (st.empty()) {
            st.push(i);
          }
        }
      }
      
    }
    return res;
    }
