import numpy as np
from pysnptools.snpreader import Bed;
from pysnptools.snpreader import Pheno;
from numpy.linalg import eigh
from math import sqrt, log, pi
from DP_util import PickTop as pt;
from scipy.stats import wishart
#from Top_STRAT_Fig import plotTop


def getData(filename):
    mph = 3;
    sFil = Bed(filename);
    yFil = Pheno(filename + ".fam");
    #y = yFil.read().val;
    y = yFil.read().val[:, mph];
    y = [i - 1 for i in y]
    return [y, sFil];


#bedFil = 'D:/Documents/SimData/Paper_Data/pop'
#bedFil = "C:/Users/H/gwasp/tests/datasets/all_chr.maf0.001.N300"

def get_X_N(bedfile = None,epsilon = 1.0,delta = 1e-5 ):
    [y, BED] = getData(bedfile)
    #X = BED.read().val
    # print(X[0,])
    # print(type(X), X.shape[0])
    X = BED.read().standardize().val
    # print(type(X))
    d = X.shape[0]
    n = X.shape[1]
    k = 2
    epsilon = epsilon
    delta = 1e-5
    beta = (d + 1) / (n * epsilon) * sqrt(2 * log((d * d + d) / (2 * sqrt(2 * pi) * delta))) + 1 / (n * sqrt(epsilon))
    N = np.random.normal(scale=beta, size=d * d)
    N = N.reshape([d, d])
    print(beta, N.shape)
    return (X , N)

def get_X_N2(bedfile = None,epsilon = 1.0,delta = 1e-5 ):
    [y, BED] = getData(bedfile)
    #X = BED.read().val
    # print(X[0,])
    # print(type(X), X.shape[0])
    X = BED.read().standardize().val
    # print(type(X))
    d = X.shape[0]
    n = X.shape[1]
    k = 2
    epsilon = epsilon
    eig_value=3.0/2*n*epsilon
    df = d+1
    scale = np.diag([eig_value] * d)
    dis = wishart(df=df,scale=scale)
    N = dis.rvs(size=1,random_state=19)

    print( N.shape)
    return (X , N)



def cal_MU(X, k, N):
    def exactSVD(X, k):
        Mat = np.dot(X, X.T) + N
        [w, v] = eigh(Mat)
        return np.asarray(v[:, :k])

    u = exactSVD(X, k)
    bot = np.sum(u ** 2, axis=0);
    bot = [sqrt(i) for i in bot]
    Uk = u / bot;

    MU_temp = X - np.dot(Uk, np.dot((Uk).T, X));

    MU = MU_temp.T;

    sd = np.sum(MU ** 2, axis=1);
    sd = [sqrt(s) for s in sd];
    MU = MU / np.asarray(sd)[:, np.newaxis];
    return MU

if __name__ == "__main__":
    [X, N] = get_X_N()
    MU = cal_MU(X, 2, N)
    print(type(MU), MU.shape)