#define ll long long int
#include <bits/stdc++.h>
#define loop(i, a, b) for (ll i = a; i < b; ++i)
#define rloop(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n)               \
    for (ll i = 0; i < n; ++i) \
        cin >> a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(), v.end()
#define dis(v)            \
    for (auto i : v)      \
        cout << i << " "; \
    cout << endl;
#define display(arr, n)         \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    srand(time(NULL));
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
using namespace std;
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.fr);
    cerr << ",";
    _print(p.sc);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

ll add(ll x, ll y)
{
    ll ans = x + y;
    return (ans >= mod ? ans - mod : ans);
}
ll sub(ll x, ll y)
{
    ll ans = x - y;
    return (ans < 0 ? ans + mod : ans);
}
ll mul(ll x, ll y)
{
    ll ans = x * y;
    return (ans >= mod ? ans % mod : ans);
}

template <class T>
class SegmentTree
{
private:
    T *st;                                                      // A pointer to the root of the ST.
    int stArrayLength;                                          // The length of the st array. (Num leaves.)
    int originalArrayLength;                                    // The length of the original array.
    void AllocateEmptyST(const std::vector<T> &);               // Allocate the space for an empty ST.
    void DeallocateST();                                        // Delete the ST previously created.
    void FillInST(const std::vector<T> &);                      // Fill the ST with the proper values.
    T RecursivelyFillST(int, int, int, const std::vector<T> &); // Recursively find, set, return min of node.
    T RecursivelySearchForMin(int, int, int, int, int);         // Recursively search a node from L to R for it's children's min values (if necessary).
    T combine(T, T);
    void RecursivelyUpdate(int, T, int, int, int); // Recursively update a node with the newValue if it's within the node's range.

public:
    SegmentTree(std::vector<T>); // Constructor
    ~SegmentTree();              // Destructor
    T query(int, int);           // Query a range from L to R.
    void update(int, T);         // Update an index to the new value T.
    void print();                // Print the current segment tree (in-order).
};
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/////////// Constructor ////////////////////////////////////
template <class T>
void SegmentTree<T>::AllocateEmptyST(const std::vector<T> &originalArray)
{
    // Calculate the number of Leaves of our st will need.
    int stHeight = ceil(log2(originalArrayLength));
    int maxNumLeaves = (2 * pow(2, stHeight)) - 1;

    // Set our private variable for the st's length.
    stArrayLength = maxNumLeaves;

    // Allocate an array of that length, and assign it to st.
    st = new T[stArrayLength];
}

template <class T>
T SegmentTree<T>::combine(T k1, T k2)
{
    return k1 + k2;
}

template <class T>
T SegmentTree<T>::RecursivelyFillST(int nodeIndex, int nodeStartIndex, int nodeEndIndex, const std::vector<T> &originalArray)
{
    if (nodeStartIndex == nodeEndIndex)
    {
        T value = originalArray[nodeStartIndex];
        st[nodeIndex] = value;
        return value;
    }
    int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

    int leftChildNodeIndex = 2 * nodeIndex + 1;
    int leftChildStartIndex = nodeStartIndex;
    int leftChildEndIndex = middleIndex;

    int rightChildNodeIndex = 2 * nodeIndex + 2;
    int rightChildStartIndex = middleIndex + 1;
    int rightChildEndIndex = nodeEndIndex;

    // Recursively find the minimum for the each child.
    T leftChildMin = RecursivelyFillST(leftChildNodeIndex, leftChildStartIndex, leftChildEndIndex, originalArray);

    T rightChildMin = RecursivelyFillST(rightChildNodeIndex, rightChildStartIndex, rightChildEndIndex, originalArray);

    // The minimum value of this node is the min between it's two children.
    T value = combine(leftChildMin, rightChildMin);

    // Set the value for this node of the st.
    st[nodeIndex] = value;

    // Return this value back up the recursion stack.
    return value;
}

template <class T>
void SegmentTree<T>::FillInST(const std::vector<T> &originalArray)
{
    // Starting with the root node of the st, recursively fill in the values in the ST.
    int rootNodeIndex = 0;
    int rootNodeStartIndex = 0;
    int rootNodeEndIndex = originalArrayLength - 1;
    RecursivelyFillST(rootNodeIndex, rootNodeStartIndex, rootNodeEndIndex, originalArray);
}

template <class T>
SegmentTree<T>::SegmentTree(std::vector<T> originalArray)
{
    originalArrayLength = originalArray.size();
    AllocateEmptyST(originalArray);
    FillInST(originalArray);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/////////// Destructor /////////////////////////////////////
template <class T>
void SegmentTree<T>::DeallocateST()
{
    // Delete the st array, set the pointer to null, and internally say the length is 0.
    delete[] st;
    st = nullptr;
    stArrayLength = 0;
    originalArrayLength = 0;
}

template <class T>
SegmentTree<T>::~SegmentTree()
{
    DeallocateST();
}
////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/////////// Query //////////////////////////////////////////
template <class T>
T SegmentTree<T>::RecursivelySearchForMin(int L, int R, int nodeIndex, int nodeStartIndex, int nodeEndIndex)
{
    // cout<<L<<" "<<R<<" "<<nodeEndIndex<<" "<<nodeStartIndex<<endl;

    if (nodeEndIndex < L || R < nodeStartIndex)
    {
        T value = 0;
        return value;
    }

    if (L <= nodeStartIndex && nodeEndIndex <= R)
    {
        T value = st[nodeIndex];
        // cout<<L<<" "<<R<<" "<<nodeEndIndex<<" "<<nodeStartIndex<<" : "<<value<<endl;
        return value;
    }
    else
    {
        int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

        int leftChildNodeIndex = 2 * nodeIndex + 1;
        int leftChildStartIndex = nodeStartIndex;
        int leftChildEndIndex = middleIndex;
        int rightChildNodeIndex = 2 * nodeIndex + 2;
        int rightChildStartIndex = middleIndex + 1;
        int rightChildEndIndex = nodeEndIndex;
        T leftChildMin = RecursivelySearchForMin(L, min(middleIndex, R), leftChildNodeIndex, leftChildStartIndex, leftChildEndIndex);
        T rightChildMin = RecursivelySearchForMin(max(L, middleIndex + 1), R, rightChildNodeIndex, rightChildStartIndex, rightChildEndIndex);
        T value = combine(leftChildMin, rightChildMin);
        // cout<<L<<" "<<R<<" "<<nodeEndIndex<<" "<<nodeStartIndex<<" : "<<value<<" "<<leftChildMin<<" "<<rightChildMin<<endl;
        return value;
    }
}

template <class T>
T SegmentTree<T>::query(int L, int R)
{
    if (L > R)
    {
        throw "L must be <= R.\n";
    }
    if (L < 0)
    {
        throw "L is outside valid range.\n";
    }
    if (R > originalArrayLength - 1)
    {
        throw "R is outside valid range.\n";
    }

    int rootNodeIndex = 0;
    int rootNodeStartIndex = 0;
    int rootNodeEndIndex = originalArrayLength - 1;
    T value = RecursivelySearchForMin(L, R, rootNodeIndex, rootNodeStartIndex, rootNodeEndIndex);
    return value;
}

template <class T>
void SegmentTree<T>::RecursivelyUpdate(int newValueIndex, T newValue, int nodeIndex, int nodeStartIndex, int nodeEndIndex)
{
    if (nodeStartIndex == nodeEndIndex && nodeStartIndex == newValueIndex)
    {
        st[nodeIndex] = newValue;
        return;
    }
    int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

    int leftChildNodeIndex = 2 * nodeIndex + 1;
    int rightChildNodeIndex = 2 * nodeIndex + 2;
    if (nodeStartIndex <= newValueIndex && newValueIndex <= middleIndex)
    {
        int leftChildStartIndex = nodeStartIndex;
        int leftChildEndIndex = middleIndex;
        RecursivelyUpdate(newValueIndex, newValue, leftChildNodeIndex, leftChildStartIndex, leftChildEndIndex);
    }
    else
    {
        int rightChildStartIndex = middleIndex + 1;
        int rightChildEndIndex = nodeEndIndex;
        RecursivelyUpdate(newValueIndex, newValue, rightChildNodeIndex, rightChildStartIndex, rightChildEndIndex);
    }
    T value = combine(st[leftChildNodeIndex], st[rightChildNodeIndex]);
    st[nodeIndex] = value;
}

template <class T>
void SegmentTree<T>::update(int newValueIndex, T newValue)
{
    if (newValueIndex < 0 || newValueIndex > originalArrayLength - 1)
    {
        throw "index is outside valid range.\n";
    }
    int rootNodeIndex = 0;
    int rootNodeStartIndex = 0;
    int rootNodeEndIndex = originalArrayLength - 1;
    RecursivelyUpdate(newValueIndex, newValue, rootNodeIndex, rootNodeStartIndex, rootNodeEndIndex);
}
template <class T>
void SegmentTree<T>::print()
{
    for (int i = 0; i < stArrayLength; i++)
    {
        std::cout << st[i] << " ";
    }

    std::cout << "\n";
}

void solve()
{
    ll n, p;
    cin >> n >> p;
    vector<ll> v(n);
    in(v, n);
    ll d;
    cin >> d;
    v = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree<ll> ss = SegmentTree<ll>(v);
    ss.print();

    // // ss.print();
    // ll final = 0;
    // // cout<<ss.query(0,3)<<endl;
    // while(d--){
    //     ll i,value; cin>>i>>value;
    //     ss.update(i-1,value);
    //     ll l = 0,r = n-1,ans = -1;
    //     while(l<=r){
    //         ll mid = (l+r)/2;
    //         ll value = ss.query(0,mid);
    //         if(value <= p)  ans = mid,l = mid+1;
    //         else r = mid-1;
    //     }
    //     final = max(final,ans+1);
    // }
    // cout<<final<<endl;
}

int main()
{
    fast int t = 1;
    while (t--)
        solve();
    return 0;
}

#define N 100010
int a[100];

int make(int *st, int ss, int se, int si)
{
    if (ss == se)
    {
        return st[si] = a[ss];
    }

    int mid = (ss + se) / 2;

    st[si] = min(make(st, ss, mid, 2 * si + 1), make(st, mid + 1, se, 2 * si + 2));
    return st[si];
}

void update(int *st, int ss, int se, int idx, int diff, int si)
{
    if (idx < ss || idx > se)
        return;

    else if (ss == se && ss == idx)
    {
        st[si] += diff;
        return;
    }

    if (ss != se)
    {
        int mid = (ss + se) >> 1;

        update(st, ss, mid, idx, diff, 2 * si + 1);
        update(st, mid + 1, se, idx, diff, 2 * si + 2);

        st[si] = min(st[2 * si + 1], st[2 * si + 2]);
    }
}

int quary(int *st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && se <= qe)
        return st[si];

    if (se < qs || ss > qe)
        return INT_MAX;

    int mid = (ss + se) >> 1;

    return min(quary(st, ss, mid, qs, qe, si * 2 + 1), quary(st, mid + 1, se, qs, qe, si * 2 + 2));
}