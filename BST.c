#include<stdio.h>
#include<malloc.h>
typedef long long ll;
struct node
{
	ll n,p;
	struct node *l,*r;
};
typedef struct node node;
node *get(ll n,ll i)
{
	node* t=(node *)malloc(sizeof(node));
	t->l=t->r=NULL;
	t->n=n;
	t->p=i;
	return t;
}
node *ins(node *t,ll n,ll i)
{
	if(!t)
	{
		printf("%lld\n",i);
		return get(n,i);
	}
	if(t->n>n) t->l=ins(t->l,n,2*i);
	else t->r=ins(t->r,n,2*i+1);
	return t;
}
node *del(node *t,ll n)
{
	if(t)
	{
		if(t->n>n) t->l=del(t->l,n);
		else if(t->n<n) t->r=del(t->r,n);
		else
		{
			printf("%lld\n",t->p);
			if(!(t->l)) 
			{
				node *x=t->r;
				free(t);
				return x;
			}
			else if(!(t->r)) 
			{
				node *x=t->l;
				free(t);
				return x;
			}
			else
			{
				node *x=t->r;
				while(x->l) x=x->l;
				t->n=x->n;
				t->r=del(t->r,t->n);
			}
		}
	}
	return t;
}
int main()
{
	ll q,n;
	char c;
	node *h=NULL;
	scanf("%lld ",&q);
	while(q--)
	{
		scanf("%c %lld ",&c,&n);
		if(c=='i') h=ins(h,n,1);
		else h=del(h,n);
	}
	return 0;
}
