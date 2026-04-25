// Solution for Maximize the Distance Between Points on a Square in JAVA

class Solution {
    long mapToPerimeter(int s,int x,int y){
        if(y==0) return x;
        if(x==s) return s+y;
        if(y==s) return 3L*s-x;
        return 4L*s-y;
    }

    boolean canPlacePoints(long[] a,int n,int k,int s,int d){
        long per=4L*s;
        for(int i=0;i<n;i++){
            int cnt=1,cur=i; long last=a[i];
            for(int step=1;step<k;step++){
                int nxt=Arrays.binarySearch(a,cur+1,i+n,last+d);
                if(nxt<0) nxt=-nxt-1;
                if(nxt>=i+n) break;
                cur=nxt; last=a[cur]; cnt++;
            }
            if(cnt==k && a[i]+per-last>=d) return true;
        }
        return false;
    }

    public int maxDistance(int side,int[][] points,int k){
        int n=points.length; long per=4L*side;
        long[] p=new long[n];
        for(int i=0;i<n;i++) p[i]=mapToPerimeter(side,points[i][0],points[i][1]);
        Arrays.sort(p);

        long[] e=new long[2*n];
        for(int i=0;i<n;i++){ e[i]=p[i]; e[i+n]=p[i]+per; }

        int l=0,r=2*side,ans=0;
        while(l<=r){
            int m=(l+r)/2;
            if(canPlacePoints(e,n,k,side,m)){ ans=m; l=m+1; }
            else r=m-1;
        }
        return ans;
    }
}
