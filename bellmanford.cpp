#include<bits/stdc++.h>
using namespace std;

class vertex                                         //node of the vertex
{
    public:                                            // containe the distance and the parent vertex address
        int distance;
    vertex* parent;
};

class edges                                           // node of the edge
{
   public:                                           //contains the address of the starting vertex, ending vertex and weight of the edge
       vertex *init;
    vertex *last;
    int weight;
};

void input(edges edg[],int i,vertex ver[])           // function for taking input
{
    int ini,en,wei;                                // ini=initial number of vertex of the edge
     cin>>ini;
     edg[i].init=&ver[ini];
    cin>>en;                                        // en= ending number of vertex of the edge
     edg[i].last=&ver[en];
    cin>>wei;                                        // wei = weight of the edge
     edg[i].weight=wei;
}

void relaxedge(edges edg[],int i)                 // function to change distance of the vertexes
{
    if(edg[i].init->distance!=INT_MAX)          //initial if it is infinity then return
    {
    if(edg[i].last->distance>(edg[i].init->distance)+(edg[i].weight))     // if distance of edge[last vertex]> distance of edge[init vertex]+ weight of the edge then
    {
        edg[i].last->distance=edg[i].init->distance+edg[i].weight;        //    distance of edge[last vertex]= distance of edge[init vertex]+ weight of the edge
        edg[i].last->parent=edg[i].init;                                  //    save the parent address in last vertex of the edge
    }
    }
}

int main()
{
        cout<<"enter the number of vertexes and the number of the edges "<<endl;         // enter the number of edges as edge number
         int vertexnumber;                                                              // enter the number of vertexes as vertexnumber
        cin>>vertexnumber;
        int edgenumber;                                                                  
        cin>>edgenumber;
       

        edges *edg=new edges[edgenumber];             // create dynamic array of edges
        vertex *ver=new vertex[vertexnumber];         // cerate dynamic array of vertexes
        cout<<"enter the starting vertex, end vertex and weight of all the edges "<<endl;
        int i=0;
        while(i<edgenumber)                   // taking the input of the initial vertex,weight ,last vertex by calling the method input
        {                                            // for all the edges
            input(edg,i, ver);
            i++;
        }
        i=0;
        while(i<vertexnumber)                   // set the distance in all vertexes as infinity
        {
            ver[i].distance=INT_MAX;
            i++;
        }

        i=0;

        int source;
        cout<<"enter the source vertex"<<endl;              // input the source from which vertex we have to find shortest path
        cin>>source;
        ver[source].distance=0;
        clock_t tstart = clock();                      // set the distance of that source vertex as zero
        while(i<vertexnumber-1)                       // call the method relaxedge for every edge for vertexnumber-1 times
        {
             int j=0;
            while(j<edgenumber)
            {
                relaxedge(edg, j);
                j++;
            }
            i++;
        }
        int flag=0;            // for check whether it is negative cycle or not, flag is zero initially
        i=0;
        while(i<edgenumber)
        {
             if(edg[i].last->distance>(edg[i].init->distance)+(edg[i].weight))     // if distance of edge[last vertex]> distance of edge[init vertex]+ weight of the edge then
            {                                                                        //    then this contains a negative cycle
                cout<<"negative cycle"<<endl;
                flag=1;
                break;                                                       // flag is 1 if it is negative cycla
            }
            i++;
        }

        i=0;
        if(flag==0)
        {
            while(i<vertexnumber)                      // show the value of output for shortest path to each vertex by the value of distance store in each vertex
            {
                if(i!=source)
                cout<<"shortest path from "<<source<<" to "<<i<<" :: "<<ver[i].distance<<endl;
                i++;
            }
        }

        cout<<"Running Time Taken :: "<<(double)((double)clock()-(double)tstart)/CLOCKS_PER_SEC<<endl;     // running time taken
    }





