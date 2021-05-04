#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np # 202055082 정보통신학부 이대로


# In[2]:


# cosine similarity
def Cos(x,y):
    xy = np.sum(x*y)
    len_x = np.sqrt(np.sum(x*x))
    len_y = np.sqrt(np.sum(y*y))
    cos_sim = xy/(len_x*len_y)
    return(cos_sim)


# In[3]:


# Manhattan distance
def Manhattan(x,y):
    dist_val = np.sum(np.abs(x-y))
    return(dist_val)


# In[4]:


# Euclidean distance
def Euclidean(x,y):
    dist_val = np.sqrt(np.sum(np.power(x-y, 2)))
    return(dist_val)


# In[5]:


# Minkowski distance
def Minkowski(x,y,r):
    r = 10
    dist_val = np.power(np.sum(np.power(x-y, r)), 1/r)
    return(dist_val)


# In[6]:


# Supremum distance
def Supremum(x,y):
    max_val = np.max(np.abs(x-y))
    dist_val = max_val
    return(dist_val)


# In[7]:


# Corrleation
def Correlation(x,y):
    x = (x-np.mean(x))/np.std(x)
    y = (y-np.mean(y))/np.std(y)
    corr_val = np.dot(x, y.transpose())
    return(corr_val)


# In[8]:


# Hamming distance
def Hamming(x,y):
    M = np.zeros([2,2])
    for k in range(0, len(x)):
        M[int(x[k]), int(y[k])] += 1
    H_dist = (M[1,0]) + (M[0,1])
    dist_val = H_dist
    
#     bin_x = format(x, 'b')
#     bin_y = format(y, 'b')
    
#     H_dist = 0
#     for k in range(0, len(b1)):
#         if bin_x[k] is not bin_y[k]:
#             H_dist += 1
#     dist_val = H_dist
    return(dist_val)


# In[9]:


# Jaccard similarity
def Jsim(x,y):
    M = np.zeros([2,2])
    for k in range(0,len(x)):
        M[int(x[k]),int(y[k])] += 1
        sim_val = (M[1,1]) / (M[0,1]+M[1,0]+M[1,1])
    return(sim_val)


# In[10]:


# Simple Matching Coefficient similarity
def SMC(x,y):
    M = np.zeros([2,2])
    for k in range(0,len(x)):
        M[int(x[k]),int(y[k])] += 1
        sim_val = (M[0,0]+M[1,1]) / (M[0,0]+M[0,1]+M[1,0]+M[1,1])
    return(sim_val)


# In[11]:


# 실습 1.
X0 = np.array([[0, 2], # pattern matrix
              [2, 0],
              [3, 1],
              [5, 1]])
dim = np.size(X0, 1) # the number of attribute
num = np.size(X0, 0) # the number of object
L1_mat = np.zeros([num,num]) # result matrix(Distance Matrix)
L2_mat = np.zeros([num,num])
L_mat = np.zeros([num,num]) 

# similarity -> 1, distance -> 0
for i in range(0, num):
    for j in range(0, num):
        x = X0[i,:]
        y = X0[j,:]
        
        if i is not j:
            (L1_dist_val) = Manhattan(x, y)
            (L2_dist_val) = Euclidean(x,y)
            (L_dist_val) = Supremum(x,y)
            L1_mat[i, j] = L1_dist_val
            L2_mat[i, j] = L2_dist_val
            L_mat[i, j] = L_dist_val
print(L1_mat)
print(np.around(L2_mat,3))
print(L_mat)


# In[12]:


# 실습 2.
X1 = np.array([[10,20,0,0],
              [30,60,0,0],
              [60,30,0,0],
              [0,0,10,20]])
dim = np.size(X1,1) # the number of attribute
num = np.size(X1,0) # the number of object
cos_mat = np.zeros([num, num]) # result matrix(Proximity Matrix)
for i in range(0, num):
    for j in range(0, num):
        x = X1[i,:]
        y = X1[j,:]
        
        if i is not j:
            (cos_sim) = Cos(x,y)
            cos_mat[i, j] = cos_sim
            
            if i<j:
                print("cos(%d,%d)=%.2f" %(i, j, cos_mat[i, j]))


# In[13]:


# 실습 3.
X2 = np.array([[1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 0, 1, 0, 0, 0, 0, 0],
              [1, 0, 1, 0, 0, 1, 1, 0, 0, 0],
              [1, 1, 1, 0, 0, 1, 1, 1, 1, 1]])
dim = np.size(X2,1) # the number of attribute
num = np.size(X2,0) # the number of object
Jsim_mat = np.zeros([num, num]) # result matrix(Proximity Matrix or Distance Matrix)
SMC_mat = np.zeros([num, num])
Hamming_mat = np.zeros([num, num])
for i in range(0, num):
    for j in range(0, num):
        x = X2[i,:]
        y = X2[j,:]
        
        if i is not j:
            for k in range(3):
                if k == 0:
                    (Jsim_val) = Jsim(x,y)
                    Jsim_mat[i, j] = Jsim_val
                elif k == 1:
                    (SMC_val) = SMC(x,y)
                    SMC_mat[i, j] = SMC_val
                elif k == 2:
                    (Ham_val) = Hamming(x,y)
                    Hamming_mat[i, j] = Ham_val
                    
            if i<j: 
                print("Jsim(%d,%d) : %.2f, " %(i, j, Jsim_mat[i, j]), end="")
                print("SMC(%d,%d) : %.2f, " %(i, j, SMC_mat[i, j]), end="")
                print("Hamming(%d,%d) : %d" %(i, j, Hamming_mat[i, j]))

