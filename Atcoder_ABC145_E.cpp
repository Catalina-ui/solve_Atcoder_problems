#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll N = 100001;
ll K = 100001;
ll mod = 1000000007;

vector<ll> fac(N), finv(N), inv(N);

void Cinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N;i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

long long com(ll n,ll k){
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){
    Cinit();
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    ll ans = 0;

    for (int i = 0; i < N;i++){
        if(i >= K - 1)
        ans += A[i] * com(i, K - 1)  % mod;
        if(N - 1 - i >= K - 1)
        ans -= A[i] * com(N - i - 1, K - 1) % mod;
        ans %= mod;
    }
    if(ans < 0)
        ans -= mod;
    cout << ans << endl;
    return 0;
}
