import numpy as np
class Conv(object):
    def __init__(self, input, weight, padding, stride):
        self.input = np.asarray(input, np.float32)
        self.weight = np.asarray(weight, np.float32)
        self.padding = padding
        self.stride = stride

    def ForwardCompute(self, input, kernel):
        [h, w] = input.shape
        [k, _] = kernel.shape

        # compute input_size after padding 
        if self.padding == "VALID":
            pad_h = 0
            pad_w = 0
            res_h = (h - k) // self.stride + 1 
            res_w = (w - k) // self.stride + 1

        if self.padding == "SAME":
            pad_h = (self.stride * (h - 1) + k - h) // 2
            pad_w = (self.stride * (w -1) + k - w) // 2
            res_h = h
            res_w = w
            
        input_pad = np.zeros([h + 2 * pad_h, w + 2 * pad_w])
        input_pad[pad_h:pad_h + h, pad_w:pad_w + w] = input
        res = np.zeros([res_h, res_w], np.float32)

        for i in range(res_h):
            for j in range(res_w):
                chunk = input_pad[i * self.stride : i * self.stride + k, j * self.stride : j * self.stride + k]
                res[i][j] = np.sum(chunk * self.kernel)
        return res

        







