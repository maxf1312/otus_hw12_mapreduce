#pragma once

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse_CSVRow(const std::string& row, char delim = ',') {
    std::vector<std::string> fields;
    std::string field;
    bool in_quotes = false;
    
    for (char c : row) 
    {
        if (!in_quotes && c == delim)
        {
            fields.push_back(field);
            field.clear();
        } else if (c == '"')
        {
            in_quotes = !in_quotes;
        } else
        {
            field += c;
        }
    }
    fields.push_back(field);
    
    return fields;
}

class CSV_Line
{
public: 
    CSV_Line() { }

    CSV_Line(std::string const& input_line, char delim = ',') 
        : line_data_{parse_CSVRow(input_line, delim)}
    {
    }

    CSV_Line& parse(std::string const& input_line, char delim = ',') 
    {
        line_data_ = parse_CSVRow(input_line, delim);
        return *this;
    }

    CSV_Line& clear(){ line_data_.clear(); return *this; } 

    std::string& operator[](size_t idx) { return line_data_.at(idx); }
    size_t       col_count() const { return line_data_.size(); }
private:
    using Cont_t = std::vector<std::string>;
    Cont_t line_data_;
};
