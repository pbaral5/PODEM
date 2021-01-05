void getobjective(Gate* Node, int *gat,int *value,int *initialgate,,LIST *Dfront)
{
    LIST* tempnode;
    LIST* tempDfrontier;
    int x;
    if (Node[*gat].Val)==2;
    Node[gat].Val=*value;
    else
    {
        updateDfrontier(Gate* Node);
        tempDfrontier=Dfront;
        for(int i=0;i< Node[tempDfrontier];i++)
        {
            tempnode=Node[tempDfrontier].Fin;
            x=Node[tempnode->Id].Val;
            if(x==2)
            {
                *gat=tempnode->Id;
                *initialgate=*gat
                //DeleteEle(&Dfront,tempDfrontier);
                break;
            }
            tempnode=tempnode->Next;
            tempDfrontier=tempDfrontier->Next;
        }
    }
}

