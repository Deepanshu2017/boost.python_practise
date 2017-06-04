#ifndef __TEMP_H
#define __TEMP_H

namespace Pooja {
	class Girl {
		public:
			Girl();
			virtual ~Girl();
			virtual void setter(int var);
			virtual int getter();
		private:
			int m_var = 10;
	};
}
#endif
