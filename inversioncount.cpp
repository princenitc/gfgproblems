ll merge(long long arr[],ll l, ll mid ,ll h) {
        ll k = l;
        ll count = 0;
        ll tmp[h+1];
        ll i = l;
        ll j = mid;
        while(i < mid && j <= h) {
            if(arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                count += mid - i;
            }
            else{
                tmp[k++] = arr[i++];
            }
        }
        while(i < mid) {
            tmp[k++] = arr[i++];
        }
        while(j <= h) {
            tmp[k++] = arr[j++];
        }
        for(int i = l;i <= h;i++)
            arr[i] = tmp[i];
    return count;
    }
    ll mergesort(long long arr[], long long l, long long h) {
        ll ans = 0;
        if(l < h) {
            ll mid = (l+h)/2;
            ans += mergesort(arr,l,mid);
            ans += mergesort(arr,mid+1,h);
            ans += merge(arr,l,mid + 1,h);
        }
    return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long l = 0;
        long long h = N-1;
        return mergesort(arr,0,h);
    }
