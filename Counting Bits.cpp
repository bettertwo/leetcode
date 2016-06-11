class Soulution 
{
public:
	vector<int> countBits(int num)
	{
        vector<int> result;
        for(int i = 0; i <= num; i++)
        {
        	int count = 0;
        	int temp = i;
        	while(temp)
        	{
        		++count;
        		temp &= (temp - 1);
        	}
        	result.push_back(count);
        }
        return result;
	}
}