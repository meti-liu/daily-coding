import random
import time

class KalmanFilter:
    def __init__(self, q=0.01, r=0.1):
        self.x_hat = 0.0      # 状态估计
        self.p = 1.0          # 估计误差协方差
        self.q = q            # 过程噪声协方差
        self.r = r            # 测量噪声协方差
        self.k = 0.0          # 卡尔曼增益
        self.bias = 0.0       # 偏差估计

    def update(self, measurement):
        self.p += self.q
        self.k = self.p / (self.p + self.r)
        self.x_hat += self.k * (measurement - self.bias - self.x_hat)
        self.p *= (1 - self.k)
        self.bias += 0.01 * (measurement - self.x_hat - self.bias)
        return self.x_hat


def main():
    print("=== 卡尔曼滤波实验模拟开始 ===")
    kf = KalmanFilter()

    # 模拟10组传感器输入数据（可替换为实际采集）
    for i in range(10):
        raw = random.uniform(4.90, 5.30)  # 模拟波动传感器输入（比如电压或距离）
        filtered = kf.update(raw)

        raw_int = int(raw * 100)
        filtered_int = int(filtered * 100)
        bias_int = int(kf.bias * 100)

        print(f"原始值: {raw_int / 100:.2f} | 滤波后: {filtered_int / 100:.2f} | 偏差估计: {bias_int / 100:.2f}")
        time.sleep(0.5)

    print("=== 滤波模拟结束 ===")


if __name__ == "__main__":
    main()
