import pandas as pd
import numpy as np
import stemgraphic
#from pandas.core.algorithms import quantile
import matplotlib.pyplot as plt

data ={'Num': [61, 64, 68, 70, 70, 71, 73, 74, 74, 76, 79, 80, 80, 83, 84, 84, 87, 89, 89, 89, 90 , 92, 95, 95, 98, 100]}
data = pd.DataFrame(data)
print("DataFrame:")
print(data)

mean = data.mean()
print("mean of Grades: ", mean)


medians=data.median()
print("medians of Grades: ",medians)

#mod = data.mod()
#print("mod of grades : ",mod)

variance = data.var()
print("variance of grades :" ,variance)

std = data.std()
print("standard deviation of grades : ",std)

qua = data.quantile([0.25,0.5,0.75])
print("quantiles of grades: ",qua)

x = range(len(data))
data['x'] = x

print(data)


# In[51]:


# create a figure and axis
fig, ax = plt.subplots()
# scatter plot
ax.scatter(data['x'], data['Num'])
# set a title and labels
ax.set_title('Scatter Plot')
ax.set_xlabel('range')
ax.set_ylabel('values')


# In[50]:


fig, ax = plt.subplots()
ax.plot(data['x'], data['Num'])
# set a title and labels
ax.set_title('Line Plot')
ax.set_xlabel('range')
ax.set_ylabel('values')


# In[47]:


# create figure and axis
fig, ax = plt.subplots()
# plot histogram
ax.hist(data['Num'])
# set title and labels
ax.set_title('Histogram Plot')
ax.set_xlabel('range')
ax.set_ylabel('values')


# In[46]:


# create figure and axis
fig, ax = plt.subplots()
# plot histogram
ax.hist(data['Num'],density=True)
# set title and labels
ax.set_title('Relative Frequency Histogram Plot')
ax.set_xlabel('range')
ax.set_ylabel('values')


# In[58]:
data_prob ={'Num': [61, 64, 68, 70, 70, 71, 73, 74, 74, 76, 79, 80, 80, 83, 84, 84, 87, 89, 89, 89, 90 , 92, 95, 95, 98, 10]}
data_prob = pd.DataFrame(data_prob)

# create figure and axis
fig, ax = plt.subplots()
# plot histogram
ax.boxplot(data_prob['Num'])
# set title and labelsp
ax.set_title('Boxplot Plot')
ax.set_xlabel('range')
ax.set_ylabel('10')

data_1 = [61, 64, 68, 70, 70, 71, 73, 74, 74, 76, 79, 80, 80, 83, 84, 84, 87, 89, 89, 89, 90 , 92, 95, 95, 98, 10]
y = pd.Series(data_1)

fig, ax = stemgraphic.stem_graphic(y)
# In[56]:


# Generating some random data (normal distribution)
# for an example
data = np.random.normal(mean, std, 26)
# mean=170, std=30, numberof elements=100
  
# Plotting the histogram.
plt.hist(data, density=True, alpha=0.6, color='b')
  
plt.show()



# In[28]:


# Generating some random data (noisy data)
# for an example
noise = np.random.normal(mean,std,26)
# mean=0, std=1, numberof elements=100
  
# Plotting the histogram.
plt.hist(noise, density=True, color='b')
  
plt.show()


# In[27]:


noise.mean(), noise.std()


# In[17]:





