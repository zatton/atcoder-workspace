// extended euclidean algorithm
// returns gcd(a, b)
ll modpow(ll a, ll b, ll mod) {
  // a ^ b % mod
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
// ax + by = gcd(a, b)
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ext_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
