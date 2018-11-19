#ifndef STATE_H
#define STATE_H

class IState {
	public:
	
		virtual void Execute() = 0;
		virtual IState * GetNextState() const = 0;
};

class StateContext {
	private: IState * _state;

	public: 
		explicit StateContext(IState *initialState);
			
		void NextState(void);
	
		IState * GetState(void) const;
			
		void Execute() const;
};
#endif
