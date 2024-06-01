#pragma once

#include "core.h"
#include "layer.h"

#include <vector>
#include <algorithm>


namespace hezel
{

class LayerStack
{
    
using StackInsertIterator = std::vector<Layer*>::iterator;
public:
    LayerStack();
    ~LayerStack();
    
    void PushLayer(Layer* layer);
    void PushOverLayer(Layer* overlay);
    void PopLayer(Layer* layer);
    void PopOverLayer(Layer* overlay);
    
    StackInsertIterator begin() { return m_layers.begin(); }
    StackInsertIterator end() { return m_layers.end(); }
    

private:
    std::vector<Layer*> m_layers;
    StackInsertIterator m_layer_insert;
};
}