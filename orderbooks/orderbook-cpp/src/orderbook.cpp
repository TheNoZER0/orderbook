#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <ctime>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <limits>
#include <string>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>

enum class OrderType {
    GoodTillCancel,
    FillandKill
};

enum class Side {
    Buy,
    Sell
};

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;

struct levelInfo {
    Price price_;
    Quantity qauntity_;
};

using levelInfos = std::vector<levelInfo>;

class OrderbookLevelInfos {
    public:
        OrderbookLevelInfos(const levelInfos& bids, const levelInfos& asks)
            : bids_(bids )
            , asks_(asks )
        { }

        const levelInfos& GetBids() const { return bids_;}
        const levelInfos& GetAsks() const {return asks_;}
    private:
        levelInfos bids_;
        levelInfos asks_;

};

class Order {
    public:
        Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
            : orderType_(orderType)
            , orderId_(orderId)
            , side_(side)
            , price_(price)
            , initialQuantity_(quantity)
            , remainingQuantity_(quantity)
        {}

        OrderId GetOrderId() const {return orderId_;}
        Side GetSide() const {return side_;}
        Price GetPrice() const {return price_;}
        OrderType GetOrderType() const {return orderType_;}
        Quantity GetInitialQuantity() const {return initialQuantity_;}
        Quantity GetRemainingQuantity() const {return remainingQuantity_;}
        Quantity GetFilledQuantity() const {return GetInitialQuantity() - GetRemainingQuantity();}

        void Fill(Quantity quantity) {

            if (quantity > GetRemainingQuantity()) {
                throw std::logic_error("Order (" + std::to_string(GetOrderId()) + ") cannot be filled for more than its remaining quantity");
            }

            remainingQuantity_ -= quantity;
        }
    private:
        OrderType orderType_;
        OrderId orderId_;
        Side side_;
        Price price_;
        Quantity initialQuantity_;
        Quantity remainingQuantity_;
};

int main() {
    return 0;
}
