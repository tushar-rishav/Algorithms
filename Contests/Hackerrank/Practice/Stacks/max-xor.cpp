using namespace std;
 
#include <bits/stdc++.h>
typedef long long ll;
# define sf(i) scanf("%lld",&(i))
# define pf(i) printf("%lld ",(i))
struct node
{
        ll data;
        struct node * left;
        struct node * right;
        ll pos;
};
 
struct node * root = new struct node;
 
void generateBinary(ll n);
ll findMax(struct node *, struct node *);
ll bits;
 
int main()
{
    ll n;
    sf(n);
   
    if(n == 1)
    {
            ll num;
            cin >> num;
            cout << "0" << endl;
            return 0;
    }
   
    ll a[n];
   
    root->data = 0;
   
    bits = 0;
   
    for(ll i=0; i<n; i++)
    {
            scanf("%lld",&a[i]);
            if(a[i] > bits)
              bits = a[i];
    }
    if(bits == 0)
      bits = 1;
    else
      bits = log2(bits) + 1;

    for(ll i=0; i<n; i++)
    {
            generateBinary(a[i]);
    }
   
    cout << findMax(root, root) << endl;
    return 0;
}
 
void generateBinary(ll n)
{
        ll binary[bits];
        for(ll i=bits-1; i>=0; i--)
        {
                ll k = n >> i;
               
                if(k & 1)
                  binary[bits-i-1] = 1;
                else
                  binary[bits-i-1] = 0;
        }
       
        struct node * p = root;
        for(ll i=0; i<bits; i++)
        {
                if(binary[i] == 0)
                {
                        if(!p->left)
                        {
                                struct node * q = new struct node;
                                q->data = 0;
                                q->pos = bits-i-1;
                                p->left = q;
                        }
                        p = p->left;
                }
                else
                {
                        if(!p->right)
                        {
                                struct node * q = new struct node;
                                q->data = 1;
                                q->pos = bits-i-1;
                                p->right = q;
                        }
                        p = p->right;
                }
        }
}
 
ll findMax(struct node * p, struct node * q)
{
        if(p == root)
        {
                if(p->left && p->right)
                  return (findMax(p->left, p->right));
                if(p->left)
                  return (findMax(p->left, p->left));
                if(p->right)
                  return (findMax(p->right, p->right));
        }
        if(p->pos == 0)
        {
                return (p->data ^ q->data);
        }
        ll x = pow(2, p->pos);
       
        ll value = x * (p->data ^ q->data);
       
        if((p->left && q->right) || (p->right && q->left))
        {
                ll x1 = 0, x2 = 0;
       
                if(p->left && q->right)
                {
                        x1 = value + findMax(p->left, q->right);
                }
                if(p->right && q->left)
                {
                        x2 = value + findMax(p->right, q->left);
                }
                return (max(x1, x2));
        }
         
        if(!p->right && !q->right)
        {
                return(value + findMax(p->left, q->left));
        }
        if(!p->left && !q->left)
        {
                return(value + findMax(p->right, q->right));
        }
        return 0;
}