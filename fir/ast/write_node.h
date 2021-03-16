#ifndef __FIR_AST_WRITE_NODE_H__
#define __FIR_AST_WRITE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing write nodes.
   */
  class write_node: public cdk::basic_node {
    bool  _nLine;
    cdk::expression_node *_argument;

  public:
    inline write_node(int lineno, cdk::expression_node *argument, bool nLine = false) :
        cdk::basic_node(lineno), _nLine(nLine), _argument(argument) {
    }
  public:
    inline bool nLine(){
        return _nLine;
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_write_node(this, level);
    }

  };

} // fir

#endif