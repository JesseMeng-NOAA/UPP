def RF(T1K,T2K,T05K,SPD1K,SPD2K,SPD05K):

    import pickle
    import numpy as np
    import pandas as pd
#    from sklearn.ensemble import RandomForestRegressor

    import warnings
    warnings.simplefilter("ignore", category=Warning)

    model = pickle.load(open('All7Sites_RF_slr_modelAGL28.pickle', "rb"))
    keys = np.load('All7Sites_slr_model_keysAGL28e.npy', allow_pickle=True)

    data = pd.DataFrame({'T1K':  [T1K],
                         'T2K':  [T2K],
                         'T05K': [T05K],
                         'SPD1K':  [SPD1K],
                         'SPD2K':  [SPD2K],
                         'SPD05K': [SPD05K]})

    data_trimmed = data.loc[:, keys]

    slr = model.predict(data_trimmed)

#    slr = T1K
    return slr

